#ifndef GRAPH_HPP    // To make sure you don't declare the function more than once by including the header multiple times.
#define GRAPH_HPP

#include <map>
#include <vector>

using namespace std;

void bfs (vector<vector<int>> adj, int root, int color[], size_t& minDegree, size_t& maxDegree);
void allComponents (vector<vector<int>> adj);
void calculateTeleports (vector<vector<int>> adj, map<tuple<int, int>, int>& teleports);

#endif
