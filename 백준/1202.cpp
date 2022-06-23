#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int ,int> pi;

int main() {
	int n, k;
	cin >> n >> k;
	vector<pi> gem;
	vector<int> bag(k);
	priority_queue<int> pq;
	for (int i = 0; i < n; i++) {
		int m, v;
		cin >> m >> v;
		gem.push_back({ m, v});
	}
	for (int i = 0; i < k; i++) {
		cin >> bag[i];
	}
	sort(gem.begin(), gem.end());
	sort(bag.begin(), bag.end());

	long long answer = 0;
	int idx = 0;
	for (int i = 0; i < k; i++) {
		while (idx < n && gem[idx].first <= bag[i]) {
			pq.push(gem[idx].second);
			idx++;
		}
		if (!pq.empty()) {
			answer += pq.top();
			pq.pop();
		}
	}
	cout << answer;
}
