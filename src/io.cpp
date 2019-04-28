#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <tuple>

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

void readfile (string filename, int& N, int& M, vector<vector<int>>& adj, vector<tuple<int, int>>& teleports) {
	int u, v;

	string line;
	vector<string> tokens;
	ifstream file(filename);

	if (file.is_open()) {
		// get dimentions
		getline (file, line);

		tokens = tokenizer(line, ' ');
		N = stoi(tokens[0]);
		M = stoi(tokens[1]);

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

			adj[u - 1].push_back(v);
			adj[v - 1].push_back(u);

			// adj.push_back(make_tuple(stoi(tokens[0]), stoi(tokens[1])));
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
			teleports.push_back(make_tuple(stoi(tokens[0]), stoi(tokens[1])));
		}

		file.close();
	} else {
		cout << "Unable to open file" << endl;
	}
}


// stdio functions =================================
void printAdjacency (vector<vector<int>> adj) {
	cout << "adjacency " << adj.size() << endl;
	for (size_t u = 0; u < adj.size(); u++) {
		cout << u + 1 << ": ";
		for (int v : adj[u]) {
			cout << v << ", ";
		}
		cout << endl;
	}
}

void printTeleports (vector<tuple<int, int>> teleports) {
	cout << "teleports" << endl;
	for (tuple<int, int> t : teleports) {
		cout << get<0>(t) << " " << get<1>(t) << endl;
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
