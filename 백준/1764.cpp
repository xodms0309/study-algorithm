#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	vector <string> notHeard;
	vector <string> answer;
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		notHeard.push_back(s);
	}
	sort(notHeard.begin(), notHeard.end());
	for (int i = 0; i < M; i++) {
		string s;
		cin >> s;
    //씨쁠쁠 알고리즘 라이브러리에 있는 이진 탐색 함수 사용
		if (binary_search(notHeard.begin(), notHeard.end(), s)) {
			answer.push_back(s);
			cnt++;
		}
	}
	cout << cnt <<"\n";
	sort(answer.begin(), answer.end());
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i]<<"\n";
	}
}
