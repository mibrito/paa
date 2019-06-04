#include <iostream>
#include <array>

using namespace std;

int * go (vector<vector<int>> board, int N, int P) {
	static int res[2] = { P, P };

	return res;
}

int main (int argc, char *argv[]) {
	int N, P, x, y;


	cin >> N;
	cin >> P;

	vector<vector<int, N>, N> board;

	// for (int i = 0; i < N; i++) {
	// 	board[i]
	// }

	int * res = go(board, N, P);
	cout << res[0] << " " << res[1] << endl;

	return 0;
}
