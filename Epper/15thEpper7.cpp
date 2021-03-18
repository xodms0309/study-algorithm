#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <pair<int, int>> v;
bool compare(pair<int, int> a, pair<int, int> b);
int solution(vector<int>s, vector<int>e, int num);
int main() {
	int num;
	cin >> num; //학생수
	vector <int> s(num);
	vector <int> e(num);
	for (int i = 0; i < num; i++) {
		cin >> s[i];
	}
	for (int i = 0; i < num; i++) {
		cin >> e[i];
	}
	cout << solution(s, e, num);

}
bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) {
		return a.first < b.first;
	} //종료시간이 같다면 시작시간이 더 빠른게 앞으로 정렬
	else {
		return a.second < b.second;
	}
}
int solution(vector<int>s, vector<int>e, int num) {
	int answer = 0;
	int e1 = 0, e2 = 0; //각 좌석의 현재 사용자
	for (int i = 0; i < num; i++) {
		v.push_back({ s[i], e[i] });
	}
	sort(v.begin(), v.end(), compare);
	for (int i = 0; i < num; i++) {
		if (e1 <= v[i].first) {
			e1 = v[i].second;
			answer++;
		}
		else if (e2 <= v[i].first) {
			e2 = e1;
			e1 = v[i].second;
			answer++;
		}
	}
	return answer;
}