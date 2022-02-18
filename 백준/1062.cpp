#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int N, K;
int answer = 0;
vector <string> middleStr;	
vector <bool> alphabet(26,false);
void checkMax() {
	int result = 0;
	for (int i = 0; i < N; i++) {
		bool checked = false;
		for (int j = 0; j <middleStr[i].length(); j++) {
			//만약 배우지 않은 알파벳이 있다면 break
			if (!alphabet[middleStr[i][j] - 97]) {
				checked = true;
				break;
			}
		}
		//모두 배웠다면 result 횟수 증가
		if (!checked) result++;	
	}
	answer = max(result, answer);
}
void learn(int idx, int alphabetNum) {
	if (alphabetNum== K-5) {
		checkMax();
	}
	else {
		for (int i = idx; i < 26; i++) {
			if (alphabet[i] == false) {
				alphabet[i] = true;
				learn(i,alphabetNum + 1);
				alphabet[i] = false;
			}
		}
	}
}
int main() {
	cin >> N >> K;
	alphabet['a' - 97] = true;
	alphabet['c' - 97] = true;
	alphabet['n' - 97] = true;
	alphabet['t' - 97] = true;
	alphabet['i' - 97] = true;
	
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		middleStr.push_back(str.substr(4, str.length() - 8));
	}

	if (K >= 5) learn(0, 0);
	cout << answer;
}
