#include <iostream>
#include <climits>
#include <vector>
#include <map>
#include <tuple>
#include <queue>

#include "io.hpp"
#include "graph.hpp"

int main (int argc, char *argv[]) {
	vector<vector<int>> adj;
	map<tuple<int, int>, int> teleports;
	queue<int> q;
	if (argc < 2) {
		cout << "Usage:" << std::endl;
		cout << "./tp2 <file.in> <file.out>" << std::endl;
	}

	readfile(argv[1], adj, teleports);

	allComponents(adj);

	// calculateTeleports(adj, teleports);


	// cout << "dimentions" << endl;
	// cout << N << " " << M << endl;
	// printAdjacency(adj);
	// printTeleports(teleports);
	// printDistances (distances);

	return 0;
}
