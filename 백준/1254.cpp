#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isPalindrome(int idx, string str) {
	int half = (str.length() - idx) / 2;
	for (int i = 0; i < half; i++) {
		if (str[idx + i] != str[str.length() - 1 - i]) return false;
	}
	return true;
}

int main() {
	string str;
	cin >> str;
	int answer = 0;
	for (int i = 0; i < str.length(); i++) {
		if (isPalindrome(i, str)) {
			answer = str.length() + i;
			break;
		}
	}
	cout << answer;
}
