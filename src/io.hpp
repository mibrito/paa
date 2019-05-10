#ifndef IO_HPP
#define IO_HPP

#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>

#include "graph.hpp"

using namespace std;

void readfile(
	string filename,
	Graph& graph,
	vector<Teleport>& teleports
);
#endif
