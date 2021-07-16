#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
vector <bool> visited;
vector <vector <int>>graph;

void dfs(int vertex) {
	visited[vertex] = true;
	cout << vertex <<" ";
	for (int i = 0; i < graph[vertex].size(); i++) {
		int next = graph[vertex][i];
		if (!visited[next]) dfs(next);
	}
}
void bfs(int vertex) {
	queue<int> q;
	visited[vertex] = true;
	q.push(vertex);
	while (!q.empty()) {
		int front = q.front();
		cout << front << " ";
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
	int V; //정점 개수
	int E; //간선 개수
	int start; //탐색을 시작할 번호
	int v1, v2;
	cin >> V >> E >> start;
	graph.resize(V + 1);
	for (int i = 0; i < E; i++) {
		cin >> v1 >> v2;
		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
	}
	for (int i = 0; i < graph.size(); i++) {
		sort(graph[i].begin(), graph[i].end());
	}
	visited = vector <bool>(V + 1, false);
	dfs(start);
	cout << "\n";
	visited = vector <bool>(V + 1, false);
	bfs(start);
}
