#include "io.hpp"

/**
 * Function that tokenizers a line by a delimiter
 * @param  line      string to be tokenized
 * @param  delimiter the delimiter for the tokenization
 * @return           an array of strings
 */
vector<string> tokenizer (string line, char delimiter) {
	// Vector of string to save tokens
	vector <string> tokens;

	// stringstream class check1
	stringstream ssCheck(line);

	string intermediate;

	// Tokenizing w.r.t. space ' '
	while(getline(ssCheck, intermediate, delimiter)) {
		tokens.push_back(intermediate);
	}

	return tokens;
}


/**
 * Function that read the input file and populates the graph and the array of displacements
 * @param filename  string with the name of the input file
 * @param g         graph to be populated
 * @param displacements vector of displacements to be populated
 */
void readfile (string filename, Graph & g, vector<Displacement>& displacements) {
	int u, v;

	string line;
	vector<string> tokens;
	ifstream file(filename);

	if (file.is_open()) {
		// get dimentions
		getline (file, line);

		// store the graph dimentions inside of the graph
		tokens = tokenizer(line, ' ');
		g.N = stoi(tokens[0]);
		g.M = stoi(tokens[1]);

		// resize the graph's adjacency list
		g.adj.resize(g.N);

		// get M edges (teleports)
		for (int m = 0; m < g.M; m++) {
			if(!getline (file, line)) {
				cout << "erro na entrada" << endl;
				file.close();
				exit(0);
			}

			tokens = tokenizer(line, ' ');
			u = stoi(tokens[0]) - 1;
			v = stoi(tokens[1]) - 1;

			// insert the node greater first on adjacency list
			if (!g.adj[u].size() || g.adj[u].back() < v) {
				g.adj[u].push_back(v);
			} else {
				g.adj[u].insert(g.adj[u].end() - 1, v);
			}

			// insert the node grater first on adjacency list
			if (!g.adj[v].size() || g.adj[v].back() < u) {
				g.adj[v].push_back(u);
			} else {
				g.adj[v].insert(g.adj[v].end() - 1, u);
			}
		}

		// get N displacements
		for (int n = 0; n < g.N; n++) {
			if(!getline (file, line)) {
				cout << "erro na entrada" << endl;
				file.close();
				exit(0);
			}

			tokens = tokenizer(line, ' ');
			u = stoi(tokens[0]) - 1;
			v = stoi(tokens[1]) - 1 ;

			// insert the displacement with the smaller position first in the order.
			if (u < v) {
				displacements.push_back(Displacement(u, v));
			} else {
				displacements.push_back(Displacement(v, u));
			}
		}

		// order the displacements by its sources
		sort(displacements.begin(), displacements.end(), Displacement::compareSources);
		file.close();
	} else {
		cout << "Unable to open file" << endl;
	}
}
