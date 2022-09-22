#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	string str;
	cin >> str;
	string first, second, third;
	vector<string> answer;

	for (int i = 1; i < str.length() - 1; i++) {
		for (int j = 1; j < str.length() - i; j++) {
			first = str.substr(0, i);
			second = str.substr(i,j);
			third = str.substr(i+j);
			
			reverse(first.begin(), first.end());
			reverse(second.begin(), second.end());
			reverse(third.begin(), third.end());
			string temp = first + second + third;
			answer.push_back(temp);
		}
		
	}
	sort(answer.begin(), answer.end());
	cout << answer[0];
}
