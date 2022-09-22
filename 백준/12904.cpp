#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	string S;
	string T;
	cin >> S >> T;

	//반대로 T에서 S가 될 수 있는지
	//1. T의 맨 뒤 A를 삭제한다.
	//2. 맨 뒤 B를 제거하고 문자열을 뒤집는다.
	int answer = 0;
	while (true) {
		if (T.length() == S.length()) {
			if (T.compare(S) == 0) answer = 1;
			break;
		}
		if (T.back() == 'A') {
			T.pop_back();
		}
		else {
			T.pop_back();
			reverse(T.begin(), T.end());
		}
	}
	cout << answer;
}
