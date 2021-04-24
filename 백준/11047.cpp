#include <iostream>
using namespace std;
int main() {
	int n; //동전 종류 수
	int money[10];
	int total_money;
	int answer = 0;
	cin >> n >> total_money;
	for (int i = 0; i < n; i++) {
		cin >> money[i];
	}
	for (int i = n-1; i >= 0; i--) {
		while (total_money >=money[i]) {
			total_money -= money[i];
			answer++;
		}	
	}
	cout << answer;
}