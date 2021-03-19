#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

double solution(vector<int>num_arr, int n) {
	double avg = 0.0;
	sort(num_arr.begin(), num_arr.end());
	if (n == 1) return num_arr[0];
	else {
		avg = (num_arr[0] + num_arr[1]) / 2.0;
		for (int i = 2; i < n; i++) {
			avg = (avg + num_arr[i]) / 2.0;
		}
		return avg;
	}
}

int main() {
	int n;
	vector<int> num_arr;
	cin >> n;
	int a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		num_arr.push_back(a);
	}

	printf("%.6f", solution(num_arr, n));
}
