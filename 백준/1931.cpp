#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool comp(pair<int, int>a, pair<int, int> b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	else
		return a.second < b.second;
}
int main() {
	int n; //È¸ÀÇ ¼ö
	int start;
	int end;
	vector<pair<int, int>> meeting;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> start >> end;
		meeting.push_back(make_pair(start, end));
	}
	sort(meeting.begin(), meeting.end(), comp);
	int time = 0;
	int answer = 0;
	for (int i = 0; i < n; i++) {
		if (time <= meeting[i].first) {
			time = meeting[i].second;
			answer++;
		}
	}
	cout << answer;
}