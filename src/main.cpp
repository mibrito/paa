#include <iostream>
#include <climits>
#include <vector>
#include <tuple>

#include "io.hpp"
#include "graph.hpp"

int main (int argc, char *argv[]) {
	int N, M;
	vector<vector<int>> adj;
	vector<tuple<int, int>> teleports;

	if (argc < 2) {
		cout << "Usage:" << std::endl;
		cout << "./tp2 <file.in> <file.out>" << std::endl;
	}

	readfile(argv[1], N, M, adj, teleports);

	vector<vector<int>> parents (N, vector<int>(N, -1));
	vector<vector<int>> distances (N, vector<int>(N, INT_MAX));
	// allDistances(adj, teleports, distances, parents);


	// cout << "dimentions" << endl;
	// cout << N << " " << M << endl;
	// printAdjacency(adj);
	// printTeleports(teleports);
	// printDistances (distances);

	return 0;
}
