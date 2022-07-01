#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str;
	cin >> str;
	vector<string> answer;
	for (int i = 0; i < str.length(); i++) {
		string temp = str.substr(i, str.length());
		answer.push_back(temp);
	}

	sort(answer.begin(), answer.end());

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << "\n";
	}

}
