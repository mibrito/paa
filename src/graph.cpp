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

using namespace std;

// bfs ========================================

// void bfs (vector<vector<int>> adj, int root, int color[], int& minDegree, int& maxDegree) {
// 	queue<int> q;
// 	// int distances[adj.size()];
//
// 	// fill(distances, distances + adj.size(), INT_MAX);
//
// 	q.push(root);
// 	color[root] = root;
// 	// distances[root] = 0;
// 	while (!q.empty()) {
// 		int u = q.front();
// 		q.pop();
//
// 		if (maxDegree < adj[u -1].size()) {
// 			maxDegree = adj[u -1].size();
// 		}
//
// 		if (minDegree > adj[u -1].size()) {
// 			minDegree = adj[u -1].size();
// 		}
//
// 		for (int v: adj[u]) {
// 			if (color[v] == WHITE) {
// 				color[v] = root;
// 				// distances[v] = distances[u] + 1;
// 				q.push(v);
// 			}
// 		}
// 	}
// }

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

void calculateTeleports (vector<vector<int>> adj, map<tuple<int, int>, int>& teleports) {
	map<tuple<int, int>, int>::iterator itr;
	for (itr = teleports.begin(); itr != teleports.end(); ++itr) {
		int u = get<0>(itr->first);
		int v = get<1>(itr->first);

		if (teleports[make_tuple(u, v)] == INT_MAX) {
			teleports[make_tuple(u, v)] = findDistance(adj, u, v);
			teleports[make_tuple(v, u)] = teleports[make_tuple(u, v)];
		}
		// cout << u << " " << v << " " << teleports[make_tuple(u, v)] << endl;
	}
}

void allComponents (vector<vector<int>> adj, vector<array<int, 2>> components) {
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

	cout << components.size() << endl;
	cout << naves[R] << " " << naves[F] << " " << naves[B] << " " << naves[T] << endl;
}
