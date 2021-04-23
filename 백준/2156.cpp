#include <iostream>
#define MAX 10001

using namespace std;
int main() {
	int n;
	int juice[MAX];
	int DP[MAX];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> juice[i];
	}
	DP[0] = juice[0];
	DP[1] = juice[0] + juice[1];
	DP[2] = max(juice[0] + juice[2], max(juice[1] + juice[2], DP[1]));
	for (int i = 3; i < n; i++) {
		DP[i] = max(juice[i] + DP[i - 2], max(juice[i]+juice[i-1]+DP[i-3], DP[i-1]));
	}
	cout << DP[n - 1];
}