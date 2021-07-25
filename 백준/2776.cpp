#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> number;
int binarySearch(int low, int high, int guess) {
	while (low <= high) {
		int mid = (low + high) / 2;
		if (number[mid] == guess) return 1;
		else if (number[mid] > guess) {
			high = mid - 1;
		}
		else low=mid+1;
	}
	return 0;
}
int main() {
	int T;
	cin >> T;
	while (T--) {
		int N, M;
		cin >> N;
		number.resize(N);
		for (int i = 0; i < N; i++) {
			scanf_s("%d", &number[i]);
		}
		sort(number.begin(), number.end());
		cin >> M;
		vector <int> guess(M);
		for (int i = 0; i < M; i++) {
			scanf_s("%d", &guess[i]);
			cout << binarySearch(0, N - 1, guess[i]) << "\n";
		}
	}
}
