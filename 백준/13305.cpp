#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int N;
	cin >> N;
	vector<long long> dist(N - 1);
	vector<long long> price(N);
	for (int i = 0; i < N - 1; i++) {
		cin >> dist[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> price[i];
	}
	if (N == 2) {
		cout << price[0]*dist[0];
		return 0;
	}
	long long oil = 0;
	int temp = price[0];
	for (int i = 0; i < N - 1; i++) {
		if (temp <= price[i]) {
			oil += temp * dist[i];
		}
		else {
			oil += price[i] * dist[i];
			temp = price[i];
		}
	}
	cout << oil;
}
