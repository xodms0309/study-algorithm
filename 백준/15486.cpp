#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 1500001
using namespace std;	

int main() {
	int N;
	cin >> N;
	vector <int> T(MAX);
	vector <int> P(MAX);
	vector <int> DP(MAX);
	int maxMoney = 0;
	for (int i = 1; i <= N; i++) {
		cin >> T[i] >> P[i];
	}
	for (int i = 1; i <=N+1; i++) {
		maxMoney = max(maxMoney, DP[i]);
		if (i + T[i] > N + 1) continue;
		DP[i + T[i]] = max(maxMoney + P[i], DP[i + T[i]]);
	}
	cout << maxMoney;
}
