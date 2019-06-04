#include <iostream>
#include <cstring>
#include <algorithm>
#include <math.h>

#include "graph.hpp"


/**
 * Function that initialize a displacement class
 * @param s source of displacement
 * @param t target of displacement
 */
Displacement::Displacement(const int s, const int t) {
	source = s;
	target = t;
}


/**
 * Function that initialize a ship class
 * @param _start the minimum index of the vector where the ship starts
 * @param _end the maximum index of the vector where the ship ends
 * @param _type type of the ship (Frigate, Recognition....)
 */
Ship::Ship (const int _start, const int _end, const int _type) {
	start = _start;
	end = _end;
	size = _end - _start + 1;
	type = _type;
}


/**
 * Function that insert a displacement of a ship inside it's vector of displacements
 * @param displacement a displacement to be inserted inside ship's displacement vector
 */
void Ship::addDisplacement (const Displacement& displacement) {
	displacements.push_back(displacement);
}


/**
 * Function that gets all displacements of battle posts and insert into it's respective
 * ship vectors of displacement
 * @param ds an ordered by source displacement vector
 */
void Graph::fillDisplacementsOnShips (const vector<Displacement>& ds) {
	size_t tKey = 0;
	// walk through the ships
	for (size_t s = 0; s < ships.size(); s++) {
		// walk through displacement vector in ascendent order of sources until it find the
		// displacements of for the current ship
		while (tKey < ds.size() && ds[tKey].source < ships[s].start) tKey++;

		// insert the sequence of displacement on the current ship
		while (tKey < ds.size() && ds[tKey].source >= ships[s].start && ds[tKey].source <= ships[s].end) {
			ships[s].addDisplacement(ds[tKey]);
			if (ds[tKey].source != ds[tKey].target) {
				ships[s].numberOfDisplacements++;
			}
			tKey++;
		}
	}
}


/**
 * Function that calculates the quantity of each kind of ship scaned by the radar
 * It uses the information that a ship is composed by a set of node ordered in sequence
 */
void Graph::calculateShipComponents () {
	int start, end, type;
	int sumDegree, maxDegree;

	start = 0;
	while (start < (int) adj.size()) {
		sumDegree = 0;
		maxDegree = 0;

		// start each component with the first node equal the last
		end = start;

		// walk through all vertices of the graph's adjacency list until it founds the
		for (int u = start; u <= end; u++) {
			// find the higher index inside each's node adjacency list and compares with the
			// higher found before, updanting the value of the higher found before with this
			// new value if it is smaller.
			end = end < adj[u].back() ? adj[u].back() : end;

			// calculate the number of egdes of each component
			sumDegree += adj[u].size();
			// calculate the maximum degree of each component
			maxDegree = maxDegree < (int) adj[u].size() ? (int) adj[u].size() : maxDegree;
		}

		// In this part of the algorithm, the type of the ship is identified.
		// if it has the number of edges equal the number of nodes minus one
		// it is a tree. In this formula both end and start are indexes, so no need
		// to add the -1 on it. In this case the component can be a Frigate or a
		// Recognition ship.
		if ((sumDegree / 2) == (end - start)) {

			// If the maximum degree is greater the two it is a Frigate ship
			if (maxDegree > 2) {
				cFri++; // increments frigate counter
				type = F;

			// If not, it has at maximum degree equal two, it is a Recognition ship
			} else {
				cRec++; // increments recognition counter
				type = R;
			}

		// If the component has more then |V|-1 edges, it has at least a cicle.
		// In this case the component can be a Bomber or a Transporter.
		} else {

			// If it has a degree greater the two, it is a Bomber ship
			if (maxDegree > 2) {
				cBom++; // increments bomber counter
				type = B;

			// If not, it has at maximum and minimum degree equal two, it is a Transporter ship
			} else {
				cTrans++; // increments transporter counter
				type = T;
			}
		}

		// creates a ship on list of ships with the information of its start and end
		// indexes, and also with its type.
		ships.push_back(Ship(start, end, type));

		// go to the next component
		start = end + 1;
	}

	// print the first solution founded
	cout << cRec << " " << cFri << " " << cBom << " " << cTrans << endl;
}


/**
 * Calculate the advantage time using the ships in its decrescent order of displacements.
 * @param displacements vector of displacements ordered in ascendent order of source index
 */
void Graph::calculateAdvantageTime (const vector<Displacement>& displacements) {
	int min = MAX, cur = 0;

	// Fill ships with its displacements
	fillDisplacementsOnShips(displacements);

	// Sort ships by the best case scenario of displacements
	sort(ships.begin(), ships.end(), Ship::compareNumberOfDisplacements);

	for (Ship ship : ships) {
		// Skip ships which the best case scenario for displacements is still bigger
		// then the minimum already found.
		// With this evaluation the algorithm avoids doing all the work of
		// calculating the All-Pair Shortest-Pairs for this ship to not
		// improve the best solution.
		if (ship.numberOfDisplacements > min) break;

		// Initialize the distances matrix for this ship
		int d[ship.size][ship.size];
		fill(d[0], d[0] + ship.size * ship.size, MAX);

		// Fill with zeros de diagonal and ones with neighbors of adjacency list
		for (int i = 0; i < ship.size; i++) {
			for (int v : adj[ship.start + i]) {
				d[i][v - ship.start] = 1;
				d[v - ship.start][i] = 1;
			}
			d[i][i] = 0;
		}

		// Calculate All-Pair Shortest-Pairs with Floyd-Warshall
		for (int k = 0; k < ship.size; k++) {
			for (int i = 0; i < ship.size; i++) {
				for (int j = i+1; j < ship.size; j++) {
					if (d[i][k] + d[k][j] < d[i][j]) {
						d[i][j] = d[i][k] + d[k][j];
						d[j][i] = d[i][j];
					}
				}
			}
		}

		// Calculate the time spent on displacementing troops between combat posts
		cur = 0;
		for (Displacement t : ship.displacements) {
			cur += d[t.source - ship.start][t.target - ship.start];
			if (cur > min) {
				break;
			}
		}

		// In case of the current ship has the minimum displacementing time
		if (cur < min) {
			min = cur;
		}
	}

	// print the second solution founded
	cout << min / 2 << endl;
}
