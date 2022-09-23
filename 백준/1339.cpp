#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> alpha(26);
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		int pow = 1;
		for (int j = str.length() - 1; j >= 0; j--) {
			alpha[str[j] - 65] += pow;
			pow *= 10;
		}
	}
	sort(alpha.begin(), alpha.end(), greater<>());
	int answer = 0;
	int num = 9;
	for (int i = 0; i <10; i++) {
		answer+=alpha[i] * num;
		num--;
	}
	cout << answer;
}

