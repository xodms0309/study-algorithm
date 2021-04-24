#include <iostream>
#include <algorithm>
#define MAX 1000
using namespace std;
int main() {
	int n;
	int P[MAX];
	int answer = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> P[i];
	}
	sort(P, P+n);
	for (int i = n-1; i >= 0; i--) {
		answer += (i + 1) * P[n-i-1];
	}
	cout << answer;
}