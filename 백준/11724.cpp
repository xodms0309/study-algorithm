#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector <vector<int>>graph;
vector<bool> visited;
int cnt = 0;
void bfs(int start) {
	queue<int> q;
	visited[start] = true;
	q.push(start);
	while (!q.empty()) {
		int front = q.front();
		q.pop();
		for (int i = 0; i < graph[front].size(); i++) {
			int next = graph[front][i];
			if (!visited[next]) {
				visited[next] = true;
				q.push(next);
			}
		}
	}
}
int main() {
	int N, M; // 정점, 간선 개수
	cin >> N >> M;
	graph.resize(N+1);
	visited.assign(N+1, false);
	for (int i = 0; i < M; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
	}
	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			bfs(i);
			cnt++;
		}
	}
	cout << cnt;
}
