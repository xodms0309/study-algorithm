#include <iostream>
using namespace std;
int cnt = 0;
int main() {
	int N;
	int cnt = 0;
	cin >> N;
	int M = N / 5;
	while (true) {
		if (M < 0) {
			break;
		}
		else if ((N - (5 * M)) % 3 == 0) {
			cnt += (N - (5 * M)) / 3;
			break;
		}
		else {
			M--;
		}
	}
	cout << M + cnt;
}
