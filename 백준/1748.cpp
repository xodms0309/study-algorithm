#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
	int n;
	cin >> n;
	string str = to_string(n);
	int digit = str.length();
	int cnt = 0;
	for (int i = 1; i < digit; i++) {
		cnt += (pow(10, i) - pow(10, i - 1))*i;
	}
	cnt += (n - pow(10, digit - 1)+1) * digit;
	cout << cnt;
}
