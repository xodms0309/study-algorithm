#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int, int> pi;
const int INF=987654321;
int main() {
	int V, E;
	cin >> V >> E;
	int start;
	cin >> start;
	vector<pi> graph[20010];
	vector<int> dist(20010);
	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		//a에서 b로가는데 c의 가중치
		graph[a].push_back({ b,c });
	}
	for (int i = 1; i <= V; i++) {
		dist[i] = INF;
	}	
	priority_queue<pi> pq;
	//시작 노드 초기화
	dist[start] = 0;
	pq.push({ 0, start });
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int currentNode = pq.top().second;
		pq.pop();
		for (int i = 0; i < graph[currentNode].size(); i++) {
			int nextNode = graph[currentNode][i].first;
			int nextCost = graph[currentNode][i].second;
			if (dist[nextNode] > cost + nextCost) {
				dist[nextNode] = cost + nextCost;
				pq.push({ -dist[nextNode],nextNode });
			}
		}
	}
	for (int i = 1; i <= V; i++) {
		if (dist[i] == INF) cout << "INF\n";
		else cout << dist[i] << "\n";
	}
}
