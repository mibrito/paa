#include <iostream>
#include <vector>
#include <array>
#include <map>
#include <tuple>
#include <queue>

#include "io.hpp"
#include "graph.hpp"

/**
 * Main function that call the functions to found the two solutions of the problem
 */
int main (int argc, char *argv[]) {
	Graph graph;
	vector<Displacement> displacements;

	// in case the user don't present the input file the executable print's its
	// usage
	if (argc < 2) {
		cout << "Usage:" << std::endl;
		cout << "./tp2 <file.in>" << std::endl;
	}

	// read the input file
	readfile(argv[1], graph, displacements);

	// calculate the ship components
	graph.calculateShipComponents();

	// calculate the advantage times
	graph.calculateAdvantageTime(displacements);
	return 0;
}
