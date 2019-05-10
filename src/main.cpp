#include <iostream>
#include <vector>
#include <array>
#include <map>
#include <tuple>
#include <queue>

#include "io.hpp"
#include "graph.hpp"

int main (int argc, char *argv[]) {
	Graph graph;
	vector<Teleport> teleports;

	if (argc < 2) {
		cout << "Usage:" << std::endl;
		cout << "./tp2 <file.in> <file.out>" << std::endl;
	}

	readfile(argv[1], graph, teleports);

	graph.calculateShips();

	graph.calculateDistances(teleports);
	return 0;
}
