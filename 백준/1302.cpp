#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

bool cmp(const pair<string, int>& a, const pair<string, int>& b) {
	if (a.second == b.second) return a.first < b.first;
	return a.second > b.second;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	map<string, int> m;
	for (int i = 0; i < n; i++) {
		string book;
		cin >> book;
		m[book]++;
	}
	vector<pair<string, int>> v(m.begin(), m.end());
	sort(v.begin(), v.end(), cmp);
	cout << v[0].first;
}
