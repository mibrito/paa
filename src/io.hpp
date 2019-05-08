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
	vector<vector<int>>& adj,
	vector<array<int, 2>>& teleports
);

void printAdjacency (vector<vector<int>> adj);
void printTeleports (vector<array<int, 2>>& teleports);
void printDistances (vector<vector<int>> distances);
#endif
