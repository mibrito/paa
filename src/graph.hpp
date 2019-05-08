#ifndef GRAPH_HPP    // To make sure you don't declare the function more than once by including the header multiple times.
#define GRAPH_HPP

#include <map>
#include <vector>
#include <list>

using namespace std;

void allComponents (vector<vector<int>> adj, vector<array<int, 3>>& components);
// void calculateDistances (vector<vector<int>> adj, vector<array<int, 2>> components);
void calculateTeleports (vector<vector<int>> adj, vector<array<int, 2>>& teleports, vector<array<int, 3>> components);

#endif
