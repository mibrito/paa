#include "io.hpp"

bool compareTeleport (array<int, 2> i, array<int, 2> j) { return (i[0] < j[0]); }

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
	vector<vector<int>>& adj,
	vector<array<int, 2>>& teleports
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

		adj.resize(N);

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
			if (!adj[u].size() || adj[u].back() < v) {
				adj[u].push_back(v);
			} else {
				adj[u].insert(adj[u].end() - 1, v);
			}

			// insert the node grater first on adjacency list
			if (!adj[v].size() || adj[v].back() < u) {
				adj[v].push_back(u);
			} else {
				adj[v].insert(adj[v].end() - 1, u);
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
				teleports.push_back({ u, v });
			} else {
				teleports.push_back({ v, u });
			}
		}

		sort(teleports.begin(), teleports.end(), compareTeleport);
		file.close();
	} else {
		cout << "Unable to open file" << endl;
	}
}


// stdio functions =================================
void printAdjacency (vector<vector<int>> adj) {
	cout << "adjacency " << adj.size() << endl;
	for (int u = 0; u < (int)adj.size(); u++) {
		cout << u + 1 << ": ";
		for (int v : adj[u]) {
			cout << v << ", ";
		}
		cout << endl;
	}
}

// void printTeleports (vector<array<int, 2>>& teleports) {
// 	cout << "teleports" << endl;
// 	vector<array<int, 2>>::iterator itr;
// 	for (itr = teleports.begin(); itr != teleports.end(); ++itr) {
// 		cout << get<0>(itr->first) << " " << get<1>(itr->first) << " " << itr->second << endl;
// 	}
// }

// void printDistances (vector<vector<int>> distances) {
// 	cout << "distances 1" << endl;
// 	for (int i = 0; i < (int)distances.size(); i++) {
// 		cout << i + 1 << ": ";
// 		for (int j = 0; j < (int)distances[i].size(); j++) {
// 			cout << " ";
// 			if (distances[i][j] != INT_MAX) {
// 				cout << distances[i][j];
// 			} else {
// 				cout << "-";
// 			}
// 			cout << " "; // << ", " << parents[i][j];
// 		}
// 		cout << endl;
// 	}
// }
