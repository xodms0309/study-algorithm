#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;	

int main() {
	int N, K;
	cin >> N >> K;
	vector <int> weight(N + 1);
	vector <int> value(N + 1);
	vector <vector<int>>DP(101, vector<int>(100001));
	for (int i = 1; i <= N; i++) {
		cin >> weight[i] >> value[i];
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			if (j - weight[i] >= 0) DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - weight[i]] + value[i]);
			else DP[i][j] = DP[i - 1][j];
		}
	}
	cout << DP[N][K];
}
