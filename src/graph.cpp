#include <iostream>
#include <climits>
#include <cstring>
#include <queue>
#include <stack>

#include "graph.hpp"

#define WHITE -1
#define GREY -2
#define BLACK -3

#define R 0
#define F 1
#define B 2
#define T 3

#define MAX 1000000001

using namespace std;

int findDistance (vector<vector<int>> adj, int source, int target) {
	queue<int> q;
	int distances[adj.size()];
	fill(distances, distances + adj.size(), INT_MAX);

	q.push(source);
	distances[source] = 0;


	while (!q.empty()) {
		int u = q.front();
		q.pop();

		for (int v: adj[u]) {
			if (distances[v] == INT_MAX) {
				distances[v] = distances[u] + 1;
				if (v == target) return distances[v];
				q.push(v);
			}
		}
	}

	return distances[target];
}

void calculateTeleports (
	vector<vector<int>> adj,
	vector<array<int, 2>>& teleports,
	vector<array<int, 3>> components
) {
	int min = INT_MAX;
	int cKey = 0;
	int cCount[components.size()] = { 0 };

	for (array<int, 2> t : teleports) {
		int u = t[0];
		int v = t[1];

		while (cKey < (int) components.size() && (u > components[cKey][1])) {
			if (cCount[cKey] < min) {
				min = cCount[cKey];
			}
			cKey++;
		}
		// frigata always number of teleports equals T - 1
		if (components[cKey][2] == F) {
			cCount[cKey] = (components[cKey][1] - components[cKey][0]) * 2;
			if (min > (components[cKey][1] - components[cKey][0]) * 2) {
				min = (components[cKey][1] - components[cKey][0]) * 2;
			}
		// other ships
		} else {
			if (cCount[cKey] < min && u != v) {
				cCount[cKey] += findDistance(adj, u, v);
			}
		}
	}

	cout << min/2 << endl;
}

// void calculateDistances (vector<vector<int>> adj, vector<array<int, 2>> components) {
// 	int start, end, cSize;
// 	for (array<int, 2> component : components) {
// 		start = component[0];
// 		end = component[1];
// 		cSize = (end - start) + 1;
//
// 		int d[cSize][cSize];
// 		fill(d[0], d[0] + cSize * cSize, MAX);
//
// 		for (int i = 0; i < cSize; i++) {
// 			d[i][i] = 0;
// 		}
// 		for (int u = 0; u < cSize; u++) {
// 			for (int v : adj[start + u]) {
// 				d[u][v - start] = 1;
// 				d[v - start][u] = 1;
// 			}
// 		}
//
// 		for (int i = 0; i < cSize; i = i + 1 ) {
// 			for (int j = 0; j < cSize; j++) {
// 				if (d[i][j] == 1) {
// 					for (int k = j; k < cSize; k++) {
// 						if (d[j][k] + 1 < d[i][k]) {
// 							d[i][k] = d[j][k] + 1;
// 							d[k][i] = d[i][k];
// 						}
// 					}
// 				}
// 			}
// 		}
//
// 		for (int u = 0; u < cSize; u++) {
// 			for (int v = 0; v < cSize; v++) {
// 				cout << d[u][v] << " ";
// 			}
// 			cout << endl;
// 		}
// 		cout << endl;
// 		//
// 		// break;
// 	}
// }

void allComponents (vector<vector<int>> adj, vector<array<int, 3>>& components) {
	int start, end;
	int sumDegree, maxDegree;
	int naves[4] = { 0 };
	int tipoNave;

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
				naves[F]++;
				tipoNave = F;
			} else {
				naves[R]++;
				tipoNave = R;
			}
		} else {
			if (maxDegree > 2) {
				naves[B]++;
				tipoNave = B;
			} else {
				naves[T]++;
				tipoNave = T;
			}
		}

		components.push_back({start, end, tipoNave});

		// go to the next component
		start = end + 1;
	}

	// cout << components.size() << endl;
	cout << naves[R] << " " << naves[F] << " " << naves[B] << " " << naves[T] << endl;
}
