#include <iostream>
#include <vector>
using namespace std;
int cnt = 0;

int main() {

	int T;
	cin >> T;
	int N;


	while (T--) {
		cin >> N;	
		vector <int> dp(N+1);	
		dp[0] = 1;
		dp[1] = 1;
		dp[2] = 2;
		for (int i = 3; i <= N; i++) {
			dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
		}
		cout << dp[N]<<"\n";
	}
}
