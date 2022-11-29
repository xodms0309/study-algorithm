#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> pi;

int main() {
	int n;
	cin >> n;
	vector<pi> rooms(n);
	for (int i = 0; i < n; i++) {
		cin >> rooms[i].first >> rooms[i].second;
	}

	sort(rooms.begin(), rooms.end());
	priority_queue<int, vector<int>, greater<>> pq;
	pq.push(rooms[0].second);
	int cnt = 0;

	for (int i = 1; i < rooms.size(); i++) {
		while (!pq.empty() && pq.top() <= rooms[i].first) {
			pq.pop();
		}
		pq.push(rooms[i].second);
		int s = pq.size();
		cnt = max(cnt, s);
	}

	cout << cnt;

}

