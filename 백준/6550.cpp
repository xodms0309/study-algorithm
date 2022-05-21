#include <iostream>
#include <vector>
#include<algorithm>
#include <string>
using namespace std;
int main() {
	string a, b;
	while (cin >> a >> b) {
		int idx = 0;
		bool isTrue = false;
		for (int i = 0; i < b.length(); i++) {
			if (a[idx] == b[i]) {
				idx++;
			}
			if (idx == a.length()) {
				isTrue = true;
				break;
			}
		}
		if (isTrue) cout << "Yes\n";
		else cout << "No\n";
	}
}
