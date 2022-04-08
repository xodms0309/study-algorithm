#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int getSum(int N, vector<int> &v) {
	int sum = 1;
	for (int i = 0; i < N; i++) {
		if (sum < v[i]) break;
		sum += v[i];
	}
	return sum;
}
int main() {
	int N;
	cin >> N;
	vector<int> v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());

	cout << getSum(N, v);
}
