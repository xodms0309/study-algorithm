/*
점화식 DP[n]=DP[n-1]+DP[n-2]
피보나치 수열과 동일
*/
#include <iostream>
#define MAX 1000000
using namespace std;
int main() {
	int n;
	cin >> n;
	int DP[MAX];
	DP[1] = 1;
	DP[2] = 2;
	for (int i = 3; i <= n; i++) {
		DP[i] = (DP[i - 1] + DP[i - 2])% 15746;
	}
	cout << DP[n];
}