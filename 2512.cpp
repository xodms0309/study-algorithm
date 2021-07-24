#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> money;
int main() {
	int N;
	long long M;
	cin >> N;
	money.resize(N);
	for (int i = 0; i < N; i++) {
		scanf_s("%d", &money[i]);
	}
	cin >> M;
	sort(money.begin(), money.end());
	int low = 0;
	int high = money.back();
	int answer = 0;
	while (low <= high) {
		int sum = 0;
		int mid = (low + high) / 2;
		for (int i = 0; i < N; i++) {
			if (money[i] - mid >= 0) sum += mid;
			else sum += money[i];
		}
		if (sum <= M) {
			if (mid > answer) answer = mid;
			low = mid + 1;
		}
		else high = mid - 1;
	}
	cout << answer;
}
