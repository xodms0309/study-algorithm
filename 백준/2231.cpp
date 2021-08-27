#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	int answer = 0;
	for (int i = 0; i < N; i++) {
		int num = i;
		int sum = 0;
		while (num != 0) {
			sum += num % 10;
			num /= 10;
		}
		if (sum + i == N) {
			answer = i;
			break;
		}
	}
	cout << answer;
}
