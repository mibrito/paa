#ifndef IO_HPP    // To make sure you don't declare the function more than once by including the header multiple times.
#define IO_HPP

using namespace std;

void readfile(string, int&, int&, vector<vector<int>>&, vector<tuple<int, int>>&);

void printAdjacency (vector<vector<int>> adj);
void printTeleports (vector<tuple<int, int>> teleports);
void printDistances (vector<vector<int>> distances);
#endif
