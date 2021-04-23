#include <iostream>
#include <stack>
using namespace std;
int main() {
	int n;
	string s;
	stack<char> st;
	bool error;
	cin >> n;
	for (int i = 0; i < n; i++) {
		error = false;
		cin >> s;
		for (int j = 0; j < s.length(); j++) {
			if (s[j] == '(') st.push(s[j]);
			else if (s[j] == ')') {
				if (!st.empty()) st.pop();
				else error = true;
			}
		}
		if (st.empty()&&!error) cout << "YES\n";
		else cout << "NO\n";
		while (!st.empty()) st.pop(); //다음 입력을 위해 스택을 비워줌
	}
}