#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int n;
	cin >> n;
	int arr[51];
	int answer = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	answer = arr[0] * arr[n - 1];
	cout << answer;
}