/*
Á¡È­½Ä DP[n]=DP[n-2]+DP[n-3]
*/
#include <iostream>
#define MAX 101
using namespace std;
int main() {
	int n;
	int t;
	cin >> t;
	long int DP[MAX] = { 0, };
	DP[1] = 1;
	DP[2] = 1;
	DP[3] = 1;
	for (int i = 4; i <= MAX-1; i++) {
		DP[i] = DP[i - 2] + DP[i - 3];
	}
	for (int i = 0; i < t; i++) {
		cin >> n;
		cout << DP[n] << '\n';
	}
}