#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
const int INF = 987654321;
typedef pair<int, int> pi;	
vector<pi> graph[200001];
vector<int> dist(200001);
void dijkstra(int V, int start) {
	for (int i = 1; i <= V; i++) {
			dist[i] = INF;
	}
	priority_queue<pi>pq;
	dist[start] = 0;
	pq.push({ 0, start });
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		for (int i = 0; i < graph[cur].size(); i++) {
			int next = graph[cur][i].first;
			int nextCost = graph[cur][i].second;
			if (dist[next] > cost + nextCost) {
				dist[next] = cost + nextCost;
				pq.push({ -dist[next], next });
			}
		}
	}
}
int main() {
	int V, E;
	cin >> V >> E;

	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
		graph[b].push_back({ a,c });
	}
	int v1, v2;
	cin >> v1 >> v2;
	//1. 1->v1->v2->V
	//2. 1->v2->v1->V
	dijkstra(V,1);
	int stoV1 = dist[v1];
	int stoV2 = dist[v2];
	dijkstra(V, v1);
	int v1tov2 = dist[v2];
	int v1toV = dist[V];
	dijkstra(V, v2);
	int v2toV = dist[V];
	int answer = INF;
	answer = min(answer, stoV1 + v1tov2 + v2toV);
	answer = min(answer, stoV2 + v1tov2 + v1toV);
	if (answer == INF) cout << -1;
	else cout << answer;
}
