#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	map<string, int> pocketmon;
	vector<string> name(n + 1);
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		pocketmon.insert({s, i + 1 });
		name[i + 1] = s;
	}
	for (int i = 0; i < m; i++) {
		string str;
		cin >> str;
		
		//숫자가 들어오면
		if (isdigit(str[0])) {
			cout << name[stoi(str)] << "\n";
		}
		else {
			auto iter = pocketmon.find(str);
			cout << iter->second<<"\n";
		}
	}
}
