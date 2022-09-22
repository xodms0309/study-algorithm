#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int, int> pi;
const int INF = 1e9;

int prim(vector<vector<pi>> &graph) {
	priority_queue<pi, vector<pi>, greater<>> pq;
	vector<bool> visited(graph.size(), false);
	int sum = 0;
	
	visited[1] = true;
	for (int i = 0; i < graph[1].size(); i++) {
		int cost = graph[1][i].first;
		int node = graph[1][i].second;
		pq.push({ cost, node });
	}

	while (!pq.empty()) {
		int current = pq.top().second;
		int cost = pq.top().first;
		pq.pop();
		if (visited[current]) continue;
		visited[current] = true;
		sum += cost;
		for (int i = 0; i < graph[current].size(); i++) {
			int nextCost = graph[current][i].first;
			int next = graph[current][i].second;
			if (visited[next]) continue;

			pq.push({ nextCost, next });
		}
	}
	return sum;
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<pi>> graph(n+1);

	//모든 컴퓨터가 연결되어야 하므로 MST
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ c, b });
		graph[b].push_back({ c, a});
	}

	cout << prim(graph);
	
}
