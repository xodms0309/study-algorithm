#include <iostream>
using namespace std;
int main() {
	int cost;
	cin >> cost;
	int pay = 1000 - cost;
	int coin[6] = { 500, 100, 50, 10, 5, 1 };
	int answer = 0;
	for (int i = 0; i < 6; i++) {
		if (pay>=coin[i]) {
			answer = answer + pay / coin[i];
			pay %= coin[i];
		}
	}
	cout << answer;
}
