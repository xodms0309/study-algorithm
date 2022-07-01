#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str;
	cin >> str;
	int num = 0;
	int cnt = 0;
	while (str.size()!=1) {
		num = 0;
		for (int i = 0; i < str.length(); i++) {
			num += str[i] - '0';
		}		
		str = to_string(num);
		cnt++;
	}
	cout << cnt << "\n";
	if (stoi(str)%3==0) cout << "YES";
	else cout << "NO";
}
