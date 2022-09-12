#include <iostream>
#include <algorithm>
#include <vector>
#include<queue>

using namespace std;
typedef pair<int, int> pi;

int main() {
	int n;
	cin >> n;
	vector<pi> oil(n);
	for (int i = 0; i < n; i++) {
		//거리, 채울 수 있는 연료
		cin >> oil[i].first >> oil[i].second;
	}
	int l, p;
	cin >> l >> p; //거리, 현재 연료 양

	sort(oil.begin(), oil.end()); //거리순으로 정렬
	priority_queue<int> pq;
	int idx = 0;
	int answer = 0;

	while (l > p) {
		//연료 p를 가지고 갈 수 있는 주유소들을 모두 pq에 넣음
		while (idx < n && oil[idx].first <= p ) {
			pq.push(oil[idx++].second);
		}
		if (pq.empty()) {
			answer = -1;
			break;
		}
		int current = pq.top();
		pq.pop();
		p += current;
		answer++;
	}
	cout << answer;
}

