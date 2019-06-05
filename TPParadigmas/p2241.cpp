#include <iostream>
#include <vector>

#define BLACK 0
#define WHITE 1
#define EMPTY 2
#define GREY 3

using namespace std;

int compare (int a, int b) {
    if ((a == b && a == BLACK) || (a == BLACK && b == EMPTY) || (b == BLACK && a == EMPTY))
        return BLACK;
    if ((a == b && a == WHITE) || (a == WHITE && b == EMPTY) || (b == WHITE && a == EMPTY))
        return WHITE;
    if (a == b && a == EMPTY)
        return EMPTY;
    return GREY;
}

int * go (vector<vector<int>> board, int N, int P) {
	static int res[2] = { P, P };

	int cols[2] = { GREY, GREY };

	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N - k - 1; i++) {
			for (int j = 0; j < N - k; j++) {
				if (j == 0) {
					// cout << "a " << i << " " << j << endl;
					cols[0] = compare(board[i][j], board[i + 1][j]);
				} else {
					// cout << "b " << i << " " << j << endl;
					cols[1] = compare(board[i][j], board[i + 1][j]);

					board[i][j-1] = compare(cols[1], cols[0]);

					res[0] += (board[i][j-1] == BLACK) ? 1 : 0;
					res[1] += (board[i][j-1] == WHITE) ? 1 : 0;

					cols[0] = cols[1];
				}
			}
		}
	}

	return res;
}

int main (int argc, char *argv[]) {
	int N, P, L, C;

	cin >> N;
	cin >> P;

	vector<vector<int>> board(N);

	for (int i = 0; i < N; i++) {
		board[i].resize(N);
		fill(board[i].begin(), board[i].end(), EMPTY);
	}

	for (int i = 0; i < P; i++) {
		cin >> L >> C;
		board[L-1][C-1] = BLACK;
	}

	for (int i = 0; i < P; i++) {
		cin >> L >> C;
		board[L-1][C-1] = WHITE;
	}

	int * res = go(board, N, P);
	cout << res[0] << " " << res[1] << endl;

	return 0;
}
