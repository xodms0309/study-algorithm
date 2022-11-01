#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> pi;
int n, m;
bool bfs(int start, int end, int cost, vector<vector<pi>> &graph) {
	queue<int> q;
	vector<bool> visited(n, false);
	q.push(start);

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		if (cur == end) return true;
		for (int i = 0; i < graph[cur].size(); i++) {
			int next = graph[cur][i].second;
			int limit = graph[cur][i].first;

			if (visited[next]) continue;
			if (cost > limit) continue;
			visited[next] = true;
			q.push(next);
		}
	}
	return false;
}

int main() {

	cin >> n >> m;
	vector<vector<pi>> graph(n+1);
	int left = 0;
	int right = 0;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ c, b });
		graph[b].push_back({ c, a });
		right = max(right, c);
	}
	int start, end;
	cin >> start >> end;

	while (left <= right) {
		int mid = (left + right) / 2;
		if (bfs(start, end, mid, graph)) left = mid + 1;
		else right = mid - 1;
	}

	cout << right;

}

