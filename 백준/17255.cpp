#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <string>

using namespace std;
string target;
set<string> s;
int cnt = 0;
void backtracking(string cur, string order, int left, int right) {
	if (cur.length() == target.length()) {
		s.insert(order);
		return;
	}

	string next = "";
	if (left - 1 >= 0) {
		next = target[left - 1]+cur;
		backtracking(next, order+next, left - 1, right);
	}

	if (right + 1 < target.length()) {
		next = cur + target[right + 1];
		backtracking(next, order + next,  left, right+1);
	}

}

int main() {
	cin >> target;
	
	for (int i = 0; i < target.length(); i++) {
		string str = "";
		str += target[i];
		backtracking(str, str, i, i);
	}

	cout << s.size();

}

