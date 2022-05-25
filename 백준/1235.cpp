#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<string> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		reverse(v[i].begin(), v[i].end());
	}
	int cnt = 1;
	while (true) {
		set<string> s;
		for (int i = 0; i < n; i++) {
			string temp = v[i].substr(0, cnt);
			s.insert(temp);
		}
		if (s.size() == n) {
			break;
		}
		cnt++;
	}
	cout << cnt;
}
