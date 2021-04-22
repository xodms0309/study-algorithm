#include <iostream>
#define MAX 301
using namespace std;
int main() {
	int n;
	int stairs[MAX];
	int DP[MAX];
	int result = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> stairs[i];
	}
	//DP[i]값은 i번째 계단을 선택했을 경우
	DP[0] = stairs[0];
	DP[1] = stairs[0] + stairs[1];
	DP[2] = max(stairs[1] + stairs[2], stairs[0] + stairs[2]);
	for (int i = 3; i < n; i++) {
		DP[i] = max(stairs[i] + DP[i - 2], stairs[i] + stairs[i - 1] + DP[i - 3]);
		//첫 번째 경우는 i번째 계단을 선택하고 i-1번째 계단 선택 x
		//두 번째 경우는 i번째 계단을 선택하고 i-1번째 계단 선택 o
	}
	cout << DP[n-1];
}