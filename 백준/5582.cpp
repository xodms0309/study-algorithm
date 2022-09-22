#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	string s1;
	string s2;
	cin >> s1 >> s2;
	int n = s1.length();
	int m = s2.length();
	int answer = 0;
	vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (s1[i] == s2[j]) {
				if (i == 0 || j == 0) dp[i][j] = 1;
				else dp[i][j] = dp[i - 1][j - 1] + 1;
				answer = max(answer, dp[i][j]);
			}
		}
	}
	cout << answer;
}
