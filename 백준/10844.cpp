#include <iostream>
using namespace std;
int main() {
	int n;
	int number = 0;
	int DP[101][10];
	cin >> n;
	DP[1][0] = 0;
	for (int i = 1; i <= 9; i++) {
		DP[1][i] = 1;
	}
	for (int i=2; i<=n; i++) {
		for (int j = 0; j <= 9; j++) {
			if (j == 0) DP[i][0] = DP[i - 1][1];
			else if (j == 9) DP[i][9] = DP[i - 1][8];
			else DP[i][j] = DP[i - 1][j - 1] + DP[i - 1][j + 1];
			DP[i][j] %= 1000000000;
		}
	}
	for (int i = 0; i <= 9; i++) {
		number += DP[n][i];
		number %= 1000000000;
	}
	cout << number% 1000000000;
}