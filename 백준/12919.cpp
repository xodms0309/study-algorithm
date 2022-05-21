#include <iostream>
#include <vector>
#include<algorithm>
#include <string>
using namespace std;
int answer = 0;

void changeStr(string S, string current) {
	string temp = "";
	if (current == S) {
		answer = 1;
		return;
	}
	if (S.size() >= current.size()) return;
	if (current[current.size() - 1] == 'A') {
		temp = current;
		temp.erase(temp.size() - 1);
		changeStr(S, temp);
	}
	if (current[0] == 'B') {
		temp = current;
		temp.erase(temp.begin());
		reverse(temp.begin(), temp.end());
		changeStr(S, temp);
	}
}
int main() {
	string S, T;
	cin >> S >> T;
	changeStr(S, T);
	cout << answer;
}
