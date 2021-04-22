#include <iostream>
#define MAX 1000001
using namespace std;
int DP[MAX];
void makeOne(int n) {
	DP[1] = 0;
	for (int i = 2; i <= n; i++) {
		//bottom up
		DP[i] = DP[i - 1] + 1; 
		if (i % 2 == 0) DP[i] = min(DP[i], DP[i / 2] + 1);
		if (i % 3 == 0) DP[i] = min(DP[i], DP[i / 3] + 1);
	}

}
int main() {
	int n;
	cin >> n;
	makeOne(n);
	cout << DP[n];
}