#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;	

int main() {
	int N;
	cin >> N;
	vector <int> arr(1001);
	vector <int> DP(1001);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	int answer = 1;
	DP[0] = 1;
	for (int i = 1; i < N; i++) {
		DP[i] = 1;
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) {
				DP[i] = max(DP[i], DP[j] + 1);
			}
		}
		answer = max(answer, DP[i]);
	}
	cout << answer;
}
