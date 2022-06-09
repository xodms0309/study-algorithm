#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	vector<int> dp(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		dp[i] = v[i];
	}
	for (int i = 1; i < n; i++) {
		dp[i] = max(dp[i], dp[i-1] + v[i]);
	}
	cout << *max_element(dp.begin(), dp.end());
}
