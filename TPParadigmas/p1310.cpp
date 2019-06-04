#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int subArraySum(vector<int> profits, int cost) {
	int vmax = INT_MIN;
	int cur = 0;

	for (int day : profits) {
		cur = cur + (day - cost);
		if (vmax < cur) {
			vmax = cur;
		}
		if (cur < 0) {
			cur = 0;
		}
	}

	return vmax > 0 ? vmax : 0;
}

int main (int argc, char *argv[]) {
	int N, cost;

	while(!(cin >> N).eof()) {

		cin >> cost;

		vector<int> profits;

		int day;
		for(int i = 0; i < N; i++) {
			cin >> day;
			profits.push_back(day);
		}

		// subArraySum(profits, cost);
		cout << subArraySum(profits, cost) << endl;
	}

	return 0;
}
