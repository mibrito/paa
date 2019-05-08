#ifndef GRAPH_HPP    // To make sure you don't declare the function more than once by including the header multiple times.
#define GRAPH_HPP

#include <map>
#include <vector>
#include <list>

using namespace std;

void allComponents (vector<vector<int>> adj, vector<array<int, 2>> components);
// void bfs (vector<vector<int>> adj, int root, int color[], int& minDegree, int& maxDegree);
void calculateTeleports (vector<vector<int>> adj, map<tuple<int, int>, int>& teleports);

#endif
