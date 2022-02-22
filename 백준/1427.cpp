#include <iostream>
#include <algorithm>
#include <string>
#include<vector>
using namespace std;	

int main() {
	int N;
	cin >> N;
	string numStr = to_string(N);
	vector<int>v;
	for (int i = 0; i < numStr.length(); i++) {
		v.push_back(numStr[i]-'0');
	}
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		cout << v[i];
	}
}
