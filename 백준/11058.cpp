#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;	

int main() {
	int N;
	cin >> N;
	vector <long long> DP(101);
	DP[0] = 0;
	for (int i = 1; i <= N; i++) {
		DP[i] = DP[i - 1] + 1;
		if (i > 6) {
			for (int j = 3; j <=5; j++) {
				DP[i] = max(DP[i], DP[i - j] * (j-1));
			}
		}
	}
	cout << DP[N];
}
