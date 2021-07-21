#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> A;
vector <int> B;
int binarySearch(int low, int high, int key) {
	while (low <= high) {
		int mid = (low + high) / 2;
		if (A[mid] == key) return 1;
		else if (A[mid] > key) high = mid - 1;
		else low = mid + 1;
	}
	return 0;
}
int main() {
	int N, M;
	cin >> N;
	A.resize(N);
	for (int i = 0; i < N; i++) {
		scanf_s("%d", &A[i]);
	}
	sort(A.begin(), A.end());
	cin >> M;
	B.resize(N);
	for (int i = 0; i < M; i++) {
		scanf_s("%d", &B[i]);
		cout << binarySearch(0, N-1, B[i]) << "\n";
	}
}
