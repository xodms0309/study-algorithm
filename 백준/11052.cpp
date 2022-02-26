#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;	

int main() {
	int N;
	cin >> N;
	vector <int> card(N+1);
	vector <int> DP(N + 1);
	for (int i = 1; i <= N; i++) {
		cin >> card[i];
	}
	DP[0] = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			DP[i] = max(DP[i], DP[i - j] + card[j]);
		}
	}
	cout << DP[N];
}
