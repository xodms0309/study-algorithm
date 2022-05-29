#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pi;
int n;
int bfs(int x, int k,vector<vector<pi>>&v) {
	vector<int> visited(n+1, false);
	queue<int>q;
	q.push(x);
	visited[x] = true;
	int cnt = 0;
	while (!q.empty()) {
		int current = q.front();
		q.pop();
		for (int i = 0; i < v[current].size(); i++) {
			int next = v[current][i].first;
			if (!visited[next] &&v[current][i].second >= k) {
				cnt++;
				q.push(next);
				visited[next] = true;
			}
		}
	}
	return cnt;
}
int main() {
	int q;
	cin >> n >> q;
	vector<vector<pi>>v(n+1);
	for (int i = 0; i < n - 1; i++) {
		int a, b, r;
		cin >> a >> b >>r;
		v[a].push_back({ b, r });
		v[b].push_back({ a, r });
	}
	for (int i = 0; i < q; i++) {
		int k, current_vid;
		cin >> k >> current_vid;
		cout << bfs(current_vid, k, v) << "\n";
	}
}


