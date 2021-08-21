#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;	
	vector <int> time(16);
	vector <int> cost(16);
	vector <int> DP(16);
	for (int i = 1; i <= N; i++) {
		cin >> time[i] >> cost[i];
	}
	for (int i = N; i >= 1; i--) {
		//일을 해도 초과될 때
		if (i + time[i] > N + 1) {
			DP[i] = DP[i + 1];
			continue;
		}
		DP[i] = max(DP[i + time[i]] + cost[i], DP[i + 1]);
	}
	cout << DP[1];
}
