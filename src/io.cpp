#include "io.hpp"

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

void readfile (
	string filename,
	vector<list<size_t>>& adj,
	map<tuple<int, int>, int>& teleports
) {
	size_t u, v;

	string line;
	vector<string> tokens;
	ifstream file(filename);

	if (file.is_open()) {
		// get dimentions
		getline (file, line);

		tokens = tokenizer(line, ' ');
		int N = stoi(tokens[0]);
		int M = stoi(tokens[1]);

		adj.resize(N);
		// cout << N << " " << M << endl;

		// get M positions
		for (int m = 0; m < M; m++) {
			if(!getline (file, line)) {
				cout << "erro na entrada" << endl;
				file.close();
				exit(0);
			}

			tokens = tokenizer(line, ' ');
			u = stoi(tokens[0]);
			v = stoi(tokens[1]);

			// insert the node grater first on adjacency list
			if (adj[u - 1].front() < v) {
				adj[u - 1].push_front(v);
			} else {
				adj[u - 1].push_back(v);
			}

			// insert the node grater first on adjacency list
			if (adj[v - 1].front() < u) {
				adj[v - 1].push_front(u);
			} else {
				adj[v - 1].push_back(u);
			}
		}

		u = -1;
		v = -1;
		// get N teleports
		for (int n = 0; n < N; n++) {
			if(!getline (file, line)) {
				cout << "erro na entrada" << endl;
				file.close();
				exit(0);
			}

			tokens = tokenizer(line, ' ');
			u = stoi(tokens[0]);
			v = stoi(tokens[1]);

			teleports[make_tuple(u, v)] = INT_MAX;
		}

		file.close();
	} else {
		cout << "Unable to open file" << endl;
	}
}


// stdio functions =================================
void printAdjacency (vector<vector<size_t>> adj) {
	cout << "adjacency " << adj.size() << endl;
	for (size_t u = 0; u < adj.size(); u++) {
		cout << u + 1 << ": ";
		for (int v : adj[u]) {
			cout << v << ", ";
		}
		cout << endl;
	}
}

void printTeleports (map<tuple<int, int>, int>& teleports) {
	cout << "teleports" << endl;
	map<tuple<int, int>, int>::iterator itr;
	for (itr = teleports.begin(); itr != teleports.end(); ++itr) {
		cout << get<0>(itr->first) << " " << get<1>(itr->first) << " " << itr->second << endl;
	}
}

void printDistances (vector<vector<int>> distances) {
	cout << "distances 1" << endl;
	for (size_t i = 0; i < distances.size(); i++) {
		cout << i + 1 << ": ";
		for (size_t j = 0; j < distances[i].size(); j++) {
			cout << " ";
			if (distances[i][j] != INT_MAX) {
				cout << distances[i][j];
			} else {
				cout << "-";
			}
			cout << " "; // << ", " << parents[i][j];
		}
		cout << endl;
	}
}
