#include <iostream>
#include <climits>
#include <cstring>
#include <queue>

#include "graph.hpp"

#define WHITE -1
#define GREY 0
#define BLACK 1

void bfs (vector<vector<int>> adj, int root) {
	queue<int> q;
	int color[adj.size()] = { WHITE };

	int parents[adj.size()] = { -1 };
	int distances[adj.size()] = { INT_MAX };

	q.push(root);
	distances[root - 1] = 0;
	color[root - 1] = GREY;
	while (!q.empty()) {
		int u = q.front();
		q.pop();

		for (int v: adj[u - 1]) {
			if (color[v - 1] == WHITE) {
				color[v - 1] = GREY;
				parents[v - 1] = u;
				distances[v - 1] = distances[u - 1] + 1;
				q.push(v);
			}
		}

		color[u - 1] = BLACK;
	}
}

int findDistance (vector<vector<int>> adj, int source, int target) {
	queue<int> q;
	int distances[adj.size()] = { INT_MAX };

	q.push(source);
	distances[source - 1] = 0;
	while (!q.empty()) {
		int u = q.front();
		q.pop();

		for (int v: adj[u - 1]) {
			if (distances[v - 1] != INT_MAX) {
				distances[v - 1] = distances[u - 1] + 1;
				if (v == target) return distances[v - 1];
				q.push(v);
			}
		}
	}

	return distances[target - 1];
}

void minTeleports (
	vector<vector<int>> adj,
	map<tuple<int, int>, int> teleports
) {
	// map<tuple<int, int>, int>::iterator itr;
	// for (tuple<int, int> teleport : teleports) {
	// 	findDistance(u + 1, adj, distances[u], parents[u]);
	// }
}
