#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int K, N;	
	int answer = 0;
	cin >> K >> N;
	vector<int> arr(K);
	for (int i = 0; i < K; i++) {
		scanf_s("%d", &arr[i]);
	}
	sort(arr.begin(), arr.end());
	long long low = 1, high = arr.back();

	while (low <= high) {	
		int cnt = 0;
		long long mid = (low + high) / 2;
		for (int i = 0; i < K; i++) {
			cnt =cnt+ (arr[i] / mid);
		}
		if (cnt >= N) {
			if (answer < mid) answer = mid;
			low = mid + 1;
		}
		else high = mid - 1;
	}
	cout << answer;
}
