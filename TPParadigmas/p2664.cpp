#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int ginastica (int T, int M, int N) {
	int MOD = pow(10, 9) + 7;
	int nValues = N - M + 1;
	int S[2][nValues] = { 0 };

	int aux = 0;
	for (int t = 1; t < T+1; t++) {
		int t2 = t % 2;
		int t2_1 = (t-1) % 2;
		for (int i = 0; i < nValues; i++) {
			if (t == 1) {
				S[t2][i] = 1;
				S[t2_1][i] = 0;
			} else {
				S[t2][i] = 0;
				if (i > 0) {
					S[t2][i] = (S[t2][i] + S[t2_1][i-1]) % MOD;
				}
				if (i < nValues - 1) {
					S[t2][i] = (S[t2][i] + S[t2_1][i+1]) % MOD;
				}
			}
		}
	}

	int sol = 0;
	for (int i = 0; i < nValues; i++) {
		sol = (sol + S[(T)%2][i]) % MOD;
	}

	return sol;
}

int main (int argc, char *argv[]) {
	int T, M, N;
	cin >> T;
	cin >> M;
	cin >> N;

	cout << ginastica(T, M, N) << endl;

	return 0;
}
