#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	string S;
	cin >> S;
	char current = S[0];
	int one = 0;
	int zero = 0;
	if (S[0] - '0') one++;
	else zero++;
	for (int i = 1; i < S.length(); i++) {
		if (S[i] != current) {
			current = S[i];
			if (S[i] - '0') one++;
			else zero++;
		}
	}
	if (!one || !zero) cout << 0;
	else cout << min(one, zero);

}	
