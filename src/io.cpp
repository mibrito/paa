#include "io.hpp"

/**
 * [tokenizer  description]
 * @param  line      [description]
 * @param  delimiter [description]
 * @return           [description]
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
 * [readfile  description]
 * @param filename  [description]
 * @param g         [description]
 * @param teleports [description]
 */
void readfile (
	string filename,
	Graph & g,
	vector<Teleport>& teleports
) {
	int u, v;

	string line;
	vector<string> tokens;
	ifstream file(filename);

	if (file.is_open()) {
		// get dimentions
		getline (file, line);

		tokens = tokenizer(line, ' ');
		int N = stoi(tokens[0]);
		int M = stoi(tokens[1]);

		g.adj.resize(N);

		// get M positions
		for (int m = 0; m < M; m++) {
			if(!getline (file, line)) {
				cout << "erro na entrada" << endl;
				file.close();
				exit(0);
			}

			tokens = tokenizer(line, ' ');
			u = stoi(tokens[0]) - 1;
			v = stoi(tokens[1]) - 1;

			// insert the node grater first on adjacency list
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

		// get N teleports
		for (int n = 0; n < N; n++) {
			if(!getline (file, line)) {
				cout << "erro na entrada" << endl;
				file.close();
				exit(0);
			}

			tokens = tokenizer(line, ' ');
			u = stoi(tokens[0]) - 1;
			v = stoi(tokens[1]) - 1 ;

			if (u < v) {
				teleports.push_back(Teleport(u, v));
			} else {
				teleports.push_back(Teleport(v, u));
			}
		}

		sort(teleports.begin(), teleports.end());
		file.close();
	} else {
		cout << "Unable to open file" << endl;
	}
}
