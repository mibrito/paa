#ifndef GRAPH_HPP    // To make sure you don't declare the function more than once by including the header multiple times.
#define GRAPH_HPP

#include <map>
#include <vector>

using namespace std;

void bfs (
	int root,
	vector<vector<int>> adj,
	vector<int>* distances,
	vector<int>& parents
);
void minTeleports (
	vector<vector<int>> adj,
	map<tuple<int, int>, int> teleports
);

#endif
