#include <iostream>
#include <vector>

using namespace std;

class Ride {
public:
	int duration;
	int score;

	Ride(int duration, int score) {
		this->duration = duration;
		this->score = score;
	}
};

int SixFlags(vector<Ride> rides, int N, int T) {
	int k[N+1][T+1];

	for (int r = 0; r <= N; r++) {
		for (int c = 0; c <= T; c++) {
			if (c == 0 || r == 0) {
				k[r][c] = 0;
			} else if (rides[r - 1].duration <= c) {
				k[r][c] = max(rides[r - 1].score + k[r][c - rides[r - 1].duration], k[r-1][c]);
			} else {
			 	k[r][c] = k[r - 1][c];
			}
		}
	}

        return k[N][T];
}

int main (int argc, char *argv[]) {
	int N, T, i = 1;
	vector<Ride> rides;

	while(cin >> N) {
		if (N == 0) break;
		cin >> T;

		int d, s;
		for(int i = 0; i < N; i++) {
			cin >> d >> s;
			rides.push_back(Ride(d, s));
		}

		cout << "Instancia " << i++ << endl;
		cout << SixFlags(rides, N, T) << endl << endl;
		rides.clear();
	}

	return 0;
}
