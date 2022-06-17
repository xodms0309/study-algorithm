#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int topologicalSort(int n, int w, vector<vector<int>> &graph, vector<int> &indegree, vector<int> &delay) {
	queue<int> q;
	vector<int> dp(n + 1);
	for (int i = 1; i <= n; i++) {
		dp[i] = delay[i];
		if (indegree[i] == 0) q.push(i);
	}
	while (!q.empty()) {
		int current = q.front();
		q.pop();

		for (int i = 0; i < graph[current].size(); i++) {
			int next = graph[current][i];
			dp[next] = max(dp[next], dp[current] + delay[next]);
			indegree[next]--;
			if (indegree[next]) continue;
			q.push(next);
		}
	}
	return dp[w];
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		vector<int> delay(n+1);
		vector<int> indegree(n + 1);
		vector<vector<int>> graph(n + 1, vector<int>(0));
		for (int i = 1; i <= n; i++) {
			cin >> delay[i];
		}
		while (k--) {
			int a, b;
			cin >> a >> b;
			graph[a].push_back(b);
			indegree[b]++;
		}
		int w;
		cin >> w;
		cout << topologicalSort(n, w, graph, indegree, delay) << "\n";
	}
}
