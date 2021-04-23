#include <iostream>
#include <stack>
using namespace std;
int main() {
	int n;
	int number;
	int sum = 0;
	stack<int> s;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> number;
		sum += number;
		if (number == 0) {
			sum -= s.top();
			s.pop();
		}
		else s.push(number);
	}
	cout << sum;
}