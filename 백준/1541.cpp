#include <iostream>
#include <string>
using namespace std;
int main() {
	string str;
	cin >> str;
	int answer = 0;
	bool minus=false;
	string temp = "";
	for (int i = 0; i <= str.size(); i++) {
		if (str[i] == '+' || str[i] == '-' || str[i] == '\0') {
			if (minus) {
				answer -= stoi(temp);
				temp = "";
			}
			else {
				answer += stoi(temp);
				temp = "";
			}
			if (str[i] == '-') 
				minus = true;
		}
		else temp += str[i];
	}
	cout << answer;
}