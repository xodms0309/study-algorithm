#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> pi;

bool cmp(pi& a, pi& b) {
	if (a.first == b.first) return a.second < b.second;
	return a.first < b.first;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;

		//중요도, 인덱스 순
		queue<pi> q;
		priority_queue<int> pq;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			q.push({ x, i});
			pq.push(x);
		}
		int cnt = 0;
		while (!q.empty()) {
			int priority = q.front().first;
			int index = q.front().second;
			q.pop();
			if (pq.top() == priority) {
				pq.pop();
				cnt++;
				if (index == m) {
					cout << cnt << "\n";
					break;
				}
			}
			else q.push({ priority, index });
		}
	}
}
