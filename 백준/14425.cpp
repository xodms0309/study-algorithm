#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	int cnt = 0;
	set<string> s;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		s.insert(str);
	}
	for (int i = 0; i < m; i++) {
		string str;
		cin >> str;
		if (s.find(str)!=s.end()) cnt++;
	}
	cout << cnt;
}
