#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;	
int main() {
	int N, X;
	cin >> N;
	vector<int> num(N);
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}
	cin >> X;	
	sort(num.begin(), num.end());
	int left = 0;
	int right = N - 1;
	int cnt = 0;
	while (left<right) {
		if (num[left] + num[right] < X) left++;
		else if (num[left] + num[right] > X) right--;
		else {
			cnt++;
			left++; right--;
		}
	}
	cout << cnt;
}
