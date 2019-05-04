#include <iostream>
#include <climits>
#include <cstring>
#include <queue>

#include "graph.hpp"

#define WHITE -1
#define GREY 0
#define BLACK 1

using namespace std;

// bfs ========================================

void bfs (vector<vector<int>> adj, int root, int& end, int color[], size_t& minDegree, size_t& maxDegree) {
	queue<int> q;
	q.push(root);
	color[root] = root;
	while (!q.empty()) {
		int u = q.front();
		if (end < u) {
			end = u;
		}
		q.pop();

		if (maxDegree < adj[u].size()) {
			maxDegree = adj[u].size();
		}

		if (minDegree > adj[u].size()) {
			minDegree = adj[u].size();
		}

		for (int v: adj[u]) {
			if (color[v] == WHITE) {
				color[v] = root;
				if (!adj[v].empty()) {
					q.push(v);
				}
			}
		}
	}
}

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

		cout << u << " " << v << " " << teleports[make_tuple(u, v)] << endl;
		if (teleports[make_tuple(u, v)] == INT_MAX) {
			teleports[make_tuple(u, v)] = findDistance(adj, u, v);
		}
	}
}

void allComponents (vector<vector<int>> adj) {
	int end;
	int R, F, B, T;
	int components = 0;

	int color[adj.size()];
	fill(color, color + adj.size(), WHITE);

	R = 0;
	F = 0;
	B = 0;
	T = 0;

	size_t minDegree, maxDegree;
	size_t u = 0;
	while (u < adj.size()) {
		minDegree = INT_MAX;
		maxDegree = 0;

		end = u;
		bfs (adj, u, end, color, minDegree, maxDegree);

		components++;

		if (maxDegree <= 2) {
			if (minDegree == 1) {
				R++;
			} else {
				T++;
			}
		} else {
			if (minDegree == 1) {
				F++;
			} else {
				B++;
			}
		}
		u = end + 1;
	}

	cout << components << endl;
	cout << "R: " << R << " F: " << F << " B: " << B << " T: " << T << endl;

	// for (int u: color) {
	// 	cout << u << " " << color[u] << endl;
	// }
}
