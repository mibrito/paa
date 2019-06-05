#include <iostream>
#include <vector>

#define BLACK -1
#define WHITE 1
#define EMPTY 0
#define GREY 5

#define IS_BLACK(x) x == BLACK
#define IS_WHITE(x) x == WHITE
#define IS_EMPTY(x) x == EMPTY
#define IS_GREY(x) x == GREY

using namespace std;

int * go (vector<vector<int>> board, int N, int P) {
	static int res[2] = { P, P };

	bool black0, black;
	bool white0, white;
	bool grey0, grey;

	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N - k; i++) {
			for (int j = 0; j < N - k + 1; j++) {
				if (j == 0) {
					black = isBlack()
				}
			}
		}
	}

	return res;
}

int main (int argc, char *argv[]) {
	int N, P, x, y;


	cin >> N;
	cin >> P;

	vector<vector<int>> board(N);

	for (int i = 0; i < N; i++) {
		board[i].resize(N);
	}

	int * res = go(board, N, P);
	cout << res[0] << " " << res[1] << endl;

	return 0;
}
