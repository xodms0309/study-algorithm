#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	long long answer = 0;
	for (int i = 0; i < n; i++) {
		answer += abs(arr[i] - (i + 1));
	}
	cout << answer;
}

