#ifndef IO_HPP    // To make sure you don't declare the function more than once by including the header multiple times.
#define IO_HPP

#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <cstring>
#include <climits>
#include <vector>
#include <list>
#include <tuple>

using namespace std;

void readfile(
	string filename,
	vector<list<size_t>>& adj,
	map<tuple<int, int>, int>& teleports
);

void printAdjacency (vector<list<size_t>> adj);
void printTeleports (map<tuple<int, int>, int>& teleports);
void printDistances (vector<vector<int>> distances);
#endif
