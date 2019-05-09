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

	vector<vector<int>> distances;

	distances.resize(components[cKey][1] - components[cKey][0] + 1);
	for (size_t i = 0; i < distances.size(); i++) {
		distances[i].resize(distances.size());
		distances[i][i] = 0;
	}

	size_t tKey = 0;
	while (tKey < teleports.size()) {
		int u = teleports[tKey][0];
		int v = teleports[tKey][1];

		while (cKey < (int) components.size() && (u > components[cKey][1])) {
			if (cCount[cKey] < min) {
				min = cCount[cKey];
			}
			cKey++;
			distances.clear();
			distances.resize(components[cKey][1] - components[cKey][0] + 1);
			for (size_t i = 0; i < distances.size(); i++) {
				distances[i].resize(distances.size());
				distances[i][i] = 0;
			}
		}

		if (cCount[cKey] < min) {
			if (distances[u - components[cKey][0]][v - components[cKey][0]]) {
				cCount[cKey] += distances[u - components[cKey][0]][v - components[cKey][0]];
			} else {
				int d = findDistance(adj, u, v);
				cCount[cKey] += u != v ? d : 0;
				distances[u - components[cKey][0]][v - components[cKey][0]] = d;
				distances[v - components[cKey][0]][u - components[cKey][0]] = d;
			}
		}
		tKey++;
	}

	cout << min/2 << endl;
}

void calculateDistances (
	vector<vector<int>> adj,
	vector<array<int, 2>> components,
	vector<array<int, 2>> teleports
) {
	int start, end, cSize, tKey=0, min = MAX, cur = 0;
	for (array<int, 2> component : components) {
		start = component[0];
		end = component[1];
		cSize = (end - start) + 1;

		int d[cSize][cSize];
		fill(d[0], d[0] + cSize * cSize, MAX);

		for (int i = 0; i < cSize; i++) {
			for (int v : adj[start + i]) {
				d[i][v - start] = 1;
				d[v - start][i] = 1;
			}
			d[i][i] = 0;
		}

		cur = 0;
		int x = tKey;
		while (x < (int) teleports.size() && teleports[x][0] < start) x++;
		for (; x < (int) teleports.size() && teleports[x][0] < end; x++) {
			if (teleports[x][0] != teleports[x][1]) {
				cur ++;
			}
		}

		if (cur > min) {
			continue;
		}

		for (int k = 0; k < cSize; k++) {
			for (int i = 0; i < cSize; i++) {
				for (int j = i+1; j < cSize; j++) {
					if (d[i][k] + d[k][j] < d[i][j]) {
						d[i][j] = d[i][k] + d[k][j];
						d[j][i] = d[i][j];
					}
				}
			}
		}

		cur = 0;
		while (tKey < (int) teleports.size() && teleports[tKey][0] < start) tKey++;
		while (tKey < (int) teleports.size() && teleports[tKey][0] < end) {
			cur += d[teleports[tKey][0] - start][teleports[tKey][1] - start];
			tKey++;
			if (cur > min) {
				break;
			}
		}
		if (cur < min) {
			min = cur;
		}

		// for (int i = 0; i < cSize; i++) {
		// 	for (int j = 0; j < cSize; j++) {
		// 		cout << d[i][j] << " ";
		// 	}
		// 	cout << endl;
		// }
		// cout << endl;
	}

	cout << min / 2 << endl;
}

void allComponents (vector<vector<int>> adj, vector<array<int, 2>>& components) {
	int start, end;
	int sumDegree, maxDegree;
	int naves[4] = { 0 };

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

		components.push_back({start, end});

		if ((sumDegree / 2) == (end - start)) {
			if (maxDegree > 2) {
				naves[F]++;
			} else {
				naves[R]++;
			}
		} else {
			if (maxDegree > 2) {
				naves[B]++;
			} else {
				naves[T]++;
			}
		}

		// go to the next component
		start = end + 1;
	}

	// cout << components.size() << endl;
	cout << naves[R] << " " << naves[F] << " " << naves[B] << " " << naves[T] << endl;
}
