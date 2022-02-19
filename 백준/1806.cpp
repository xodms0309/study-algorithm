#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int N, S;
	int answer = 100000;
	cin >> N >> S;
	vector <int> arr(N);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	int left = 0, right = 0;
	int sum = 0;
	while (left <= right) {
		if (sum >= S) {
			answer = min(answer, right - left);
			sum -= arr[left++];
		}
		else { 
			if (right == N) break;
			sum += arr[right++];
		}
	}
	if (answer == 100000) cout << 0;
	else cout << answer;
}
