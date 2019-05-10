#include <iostream>
#include <climits>
#include <cstring>
#include <queue>
#include <stack>
#include <algorithm>

#include "graph.hpp"

Teleport::Teleport(int s, int t) {
	source = s;
	target = t;
}

Ship::Ship(int s, int e, int t) {
	start = s;
	end = e;
	size = e - s + 1;
	type = t;
}

bool Ship::operator < (Ship & other) {
	return minTeleports < other.minTeleports;
}

void Ship::addTeleport (Teleport teleport) {
	teleports.push_back(teleport);
}

void Graph::fillTeleports (vector<Teleport> ts) {
	size_t tKey = 0;
	for (size_t s = 0; s < ships.size(); s++) {
		while (tKey < ts.size() && ts[tKey].source < ships[s].start) tKey++;
		while (tKey < ts.size() && ts[tKey].source >= ships[s].start && ts[tKey].source <= ships[s].end) {
			ships[s].addTeleport(ts[tKey]);
			if (ts[tKey].source != ts[tKey].target) {
				ships[s].minTeleports++;
			}
			tKey++;
		}
	}
}

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

	// cout << components.size() << endl;
	cout << cRec << " " << cFri << " " << cBom << " " << cTrans << endl;
}

void Graph::calculateDistances (vector<Teleport> teleports) {
	int min = MAX, cur = 0;

	fillTeleports(teleports);
	std::sort(ships.begin(), ships.end());

	for (Ship ship : ships) {
		if (ship.minTeleports > min) continue;

		int d[ship.size][ship.size];
		fill(d[0], d[0] + ship.size * ship.size, MAX);

		for (int i = 0; i < ship.size; i++) {
			for (int v : adj[ship.start + i]) {
				d[i][v - ship.start] = 1;
				d[v - ship.start][i] = 1;
			}
			d[i][i] = 0;
		}

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

		cur = 0;
		for (Teleport t : ship.teleports) {
			cur += d[t.source - ship.start][t.target - ship.start];
			if (cur > min) {
				break;
			}
		}
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
