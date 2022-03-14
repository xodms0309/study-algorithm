#include <iostream>
#include <vector>
using namespace std;
int main() {
	string str;
	cin >> str;
	vector<long long> dp(str.length() + 1);
	if (str[0] == '0') {
		cout << 0;
		exit(0);
	}
	dp[0] = dp[1] = 1;
	for (int i = 2; i <= str.length(); i++) {
		int curIdx = i - 1; //DP는 index 1부터 시작하고 str은 0부터 탐색함
		//0, 30, 40...인 경우
		if (str[curIdx] == '0' && (str[curIdx - 1] < '1' || str[curIdx - 1]>'2')) {
			cout << 0;
			exit(0);
		}
		if (str[curIdx] != '0') 
			dp[i] += dp[i - 1];
		if (str[curIdx - 1] == '1' || (str[curIdx] <= '6' && str[curIdx - 1] == '2')) 
			dp[i] += dp[i - 2];
		dp[i] %= 1000000;
	}
	cout << dp[str.length()];
}
