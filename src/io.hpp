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

#include "graph.hpp"

using namespace std;

void readfile(
	string filename,
	Graph& graph,
	vector<Teleport>& teleports
);
#endif
