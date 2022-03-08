#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(const string& a, const string& b) {
	return a.length() < b.length();
}
int main() {
	int N;
	cin >> N;
	vector <string> word(N);
	for (int i = 0; i < N; i++) {
		cin >> word[i];
	}
	sort(word.begin(), word.end(), cmp);
	int prefix = 0;
	bool hasPrefix=false;
	for (int i = 0; i < N; i++) {			
		hasPrefix = false;
		for (int j = i + 1; j < N; j++) {
			if (word[j].length() < word[i].length()) break;
			if (word[j].substr(0, word[i].length())==word[i]) {
				hasPrefix = true;
			}
		}
		if (hasPrefix) prefix++;
	}
	if (prefix == N) cout << 1;
	else cout << N - prefix;
}
