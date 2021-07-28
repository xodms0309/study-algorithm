#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int>A(N);
	vector<int>B(N);
	for (int i = 0; i < N; i++) {
		scanf_s("%d", &A[i]);
	}
	for (int i = 0; i < N; i++) {
		scanf_s("%d", &B[i]);
	}
	sort(A.begin(), A.end());
	int sum = 0;
	while (B.size()) {
		int max = *max_element(B.begin(), B.end());
		int max_index= max_element(B.begin(), B.end())-B.begin();
		sum += A.front() * max;
		A.erase(A.begin());
		B.erase(B.begin()+max_index);
	}
	cout << sum;
}
