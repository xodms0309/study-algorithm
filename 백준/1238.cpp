#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> pi;
const int INF = 1e9;

void dijkstra(int start, vector<vector<pi>> &graph, vector<int> &dist) {
	priority_queue<pi, vector<pi>, greater<>> pq;
	pq.push({ 0, start });
	dist[start] = 0;
	while (!pq.empty()) {
		int cost = pq.top().first;
		int node = pq.top().second;
		pq.pop();
		for (int i = 0; i < graph[node].size(); i++) {
			int next = graph[node][i].second;
			int nextCost = graph[node][i].first+cost;
			if (dist[next] > nextCost) {
				dist[next] = nextCost;
				pq.push({ nextCost, next });
			}
		}
	}
}

int main() {

	int n, m, x;
	cin >> n >> m >> x;//출발지는 x마을

	//단방향 도로
	vector<vector<pi>> graph(n + 1);
	vector<int> dist(n+1, INF);
	vector<int> to_dist(n + 1, INF);

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ c, b }); //a에서 b까지 가는데 c만큼 걸림
	}

	for (int i = 1; i <= n; i++) {
		if (i == x) to_dist[i] = 0;
		dist.clear();
		dist.resize(n + 1, INF);

		dijkstra(i, graph, dist);
		to_dist[i] = dist[x]; //i에서 출발해서 x로 가는 거리
	}

	dist.clear();
	dist.resize(n + 1, INF);
	dijkstra(x, graph, dist);

	int answer = 0;
	for (int i = 1; i <= n; i++) {
		answer = max(answer, dist[i] + to_dist[i]);
	}
	cout << answer;
}

