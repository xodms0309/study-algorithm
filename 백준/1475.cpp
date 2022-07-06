#include <iostream>
#include <map>
using namespace std;

int main() {
	map<int, int>m;
	string str;
	cin >> str;
	int six = 0;
	int nine = 0;
	for (int i = 0; i < str.length(); i++) {
		int num = str[i] - '0';
		if (num == 6) six++;
		else if (num == 9) nine++;
		m[num]++;
	}
	int max_cnt = (six+nine+1)/2;
	for (auto [num, cnt] : m) {
		if (num == 6 || num == 9) continue;
		max_cnt = max(max_cnt, cnt);
	}
	cout << max_cnt;
}
