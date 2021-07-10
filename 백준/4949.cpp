
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
	while (true) {
		string str;
		int isError = 0;
		getline(cin, str);
		vector<char> stack;
		if (str == ".") break;
		for (int i = 0; i < str.length(); i++) {
			if (str[i] == '(' || str[i] == '[') stack.push_back(str[i]);
			else if (str[i] == ')') {
				if (stack.size() == 0 || stack.back() != '(') {
					isError = 1;
					break;
				}
				else {
					if (stack.back() == '(') stack.pop_back();
				}
			}
			else if (str[i] == ']') {
				if (stack.size() == 0|| stack.back() != '[') {
					isError = 1;
					break;
				}
				else {
					if (stack.back() == '[') stack.pop_back();
				}
			}

		}
		if (isError || !stack.empty()) cout << "no\n";
		else cout << "yes\n";
	}
}
