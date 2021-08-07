#include <iostream>
#include <string>
#include <list>
using namespace std;
int main() {
	string str;
	cin >> str;
	list <char> list(str.begin(), str.end());
	int n;
	cin >> n;
	auto current = list.end();
	char command;
	while (n--) {
		int l = str.length();
		cin >> command;
		if (command == 'L') {
			if (current != list.begin())
				current--;
		}
		else if (command == 'D') {
			if (current !=list.end())
				current++;
		}
		else if (command == 'B') {
			if (current !=list.begin()) {
				--current;
				current=list.erase(current);
			}
		}
		else if (command == 'P') {
			char ch;
			cin >> ch;
			list.insert(current, ch);
		}
		
	}
	for (auto c : list) cout << c;
}
