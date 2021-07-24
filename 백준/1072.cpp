#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	long long X, Y;
	cin >> X >> Y;
	int Z; //현재 승률
	Z = (Y * 100) / X;
	int answer = 0;
	if (Z >= 99) {
		cout << -1;
		return 0;
	}
	int low = 0; int high = 1000000000;
	while (low<=high) {
		int mid = (low + high) / 2;
		int nextZ = (100 * (Y + mid)) / (X + mid);
		if (Z>=nextZ) {
			answer = mid + 1;
			low = mid + 1;
		}
		else high = mid - 1;
	}
	cout << answer;
}
