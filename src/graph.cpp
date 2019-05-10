#include <iostream>
#include <cstring>
#include <algorithm>

#include "graph.hpp"


/**
 * [Teleport::Teleport description]
 * @param s [description]
 * @param t [description]
 */
Teleport::Teleport(const int s, const int t) {
	source = s;
	target = t;
}


/**
 * [Ship::Ship description]
 * @param s [description]
 * @param e [description]
 * @param t [description]
 */
Ship::Ship (const int start, const int end, const int type) {
	this->start = start;
	this->end = end;
	this->size = end - start + 1;
	this->type = type;
}


/**
 * [Ship::addTeleport  description]
 * @param teleport [description]
 */
void Ship::addTeleport (const Teleport& teleport) {
	teleports.push_back(teleport);
}


/**
 * [Graph::fillTeleports  description]
 * @param ts [description]
 */
void Graph::addTeleportsOnShips (const vector<Teleport>& ts) {
	size_t tKey = 0;
	for (size_t s = 0; s < ships.size(); s++) {
		while (tKey < ts.size() && ts[tKey].source < ships[s].start) tKey++;
		while (tKey < ts.size() && ts[tKey].source >= ships[s].start && ts[tKey].source <= ships[s].end) {
			ships[s].addTeleport(ts[tKey]);
			if (ts[tKey].source != ts[tKey].target) {
				ships[s].numberOfTeleports++;
			}
			tKey++;
		}
	}
}


/**
 * [Graph::calculateShips  description]
 */
void Graph::calculateShips () {
	int start, end, type;
	int sumDegree, maxDegree;

	start = 0;
	while (start < (int) adj.size()) {
		sumDegree = 0;
		maxDegree = 0;

		end = start;
		for (int u = start; u <= end; u++) {
			end = end < adj[u].back() ? adj[u].back() : end;

			sumDegree += adj[u].size();
			maxDegree = maxDegree < (int) adj[u].size() ? (int) adj[u].size() : maxDegree;
		}

		if ((sumDegree / 2) == (end - start)) {
			if (maxDegree > 2) {
				cFri++;
				type = F;
			} else {
				cRec++;
				type = R;
			}
		} else {
			if (maxDegree > 2) {
				cBom++;
				type = B;
			} else {
				cTrans++;
				type = T;
			}
		}

		ships.push_back(Ship(start, end, type));
		// go to the next component
		start = end + 1;
	}

	cout << cRec << " " << cFri << " " << cBom << " " << cTrans << endl;
}


/**
 * [Graph::calculateDistances  description]
 * @param teleports [description]
 */
void Graph::calculateAdvantageTime (const vector<Teleport>& teleports) {
	int min = MAX, cur = 0;

	// Fill ships with its teleports
	addTeleportsOnShips(teleports);

	// Sort ships by the best case scenario of teleports
	sort(ships.begin(), ships.end(), Ship::compareNumberOfTeleports);

	for (Ship ship : ships) {
		// Skip ships which the best case scenario for teleports is still bigger
		// then the minimum already found.
		// With this evaluation the algorithm avoids doing all the work of
		// calculating the All-Pair Shortest-Pairs for this ship to not
		// improve the best solution.
		if (ship.numberOfTeleports > min) break;

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

		// Calculate the time spent on teleporting troops between combat posts
		cur = 0;
		for (Teleport t : ship.teleports) {
			cur += d[t.source - ship.start][t.target - ship.start];
			if (cur > min) {
				break;
			}
		}

		// In case of the current ship has the minimum teleporting time
		if (cur < min) {
			min = cur;
		}

		// for (int i = 0; i < ship.size; i++) {
		// 	for (int j = 0; j < ship.size; j++) {
		// 		cout << d[i][j] << " ";
		// 	}
		// 	cout << endl;
		// }
		// cout << endl;
	}

	cout << min / 2 << endl;
}
