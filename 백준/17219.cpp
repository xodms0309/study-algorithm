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
	map<string, string> info;
	for (int i = 0; i < n; i++) {
		string site, password;
		cin >> site >> password;
		info.insert({ site, password });
	}
	for (int i = 0; i < m; i++) {
		string site;
		cin >> site;
		cout << info[site]<<"\n";
	}
}
