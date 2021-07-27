#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int>A;
vector<int>B;
int binarySearch(int low, int high, int key) {
	while (low <= high) {
		int mid = (low + high) / 2;
		if (B[mid] < key) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	return low;
}
int main() {
	int T;
	cin >> T;
	while (T--) {
		int N, M;
		int cnt = 0;
		cin >> N >> M;
		A.resize(N);
		B.resize(M);
		for (int i = 0; i < N; i++) {
			scanf_s("%d", &A[i]);
		}
		for (int i = 0; i < M; i++) {
			scanf_s("%d", &B[i]);
		}
		sort(A.begin(), A.end());
		sort(B.begin(), B.end());
		for (int i = 0; i < N; i++) {
			cnt += binarySearch(0, M - 1, A[i]);
		}
		cout << cnt << "\n";
	}
}
