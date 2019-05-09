#include <iostream>
#include <climits>
#include <vector>
#include <array>
#include <map>
#include <tuple>
#include <queue>

#include "io.hpp"
#include "graph.hpp"

int main (int argc, char *argv[]) {
	vector<vector<int>> adj;
	vector<array<int, 2>> teleports;
	vector<array<int, 2>> components;

	if (argc < 2) {
		cout << "Usage:" << std::endl;
		cout << "./tp2 <file.in> <file.out>" << std::endl;
	}

	readfile(argv[1], adj, teleports);

	allComponents(adj, components);

	// calculateTeleports(adj, teleports, components);

	calculateDistances(adj, components, teleports);
	return 0;
}
