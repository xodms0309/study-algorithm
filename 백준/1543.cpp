#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str, find_str;
	//공백 포함이라 이렇게 입력을 받아야 함
	getline(cin, str);
	getline(cin, find_str);
	int len = find_str.length();
	int current = 0;
	int cnt = 0;
	while (true) {
		if (current >= str.length()) break;
		string temp = str.substr(current, len);
		if (temp == find_str) {
			cnt++;
			current += len;
		}
		else current++;
	}
	cout << cnt;
}
