#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int checkDiff(string a, string b, int diff) {
	int cnt = 0;
	for (int i = 0; i< a.length(); i++) {
		if (a[i] != b[i+diff]) cnt++;
	}
	return cnt;
}
int main() {
	string a, b;
	cin >> a >> b;
	int diff = b.length() - a.length();
	int answer = 50;
	if (diff == 0) {
		cout << checkDiff(a, b, 0);
		return 0;
	}
	for (int i = 0; i <= diff; i++) {
		answer = min(answer, checkDiff(a,b,i));
	}
	cout << answer;
}
