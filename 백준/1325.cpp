#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>>graph;
vector <bool> visited;
int cnt;
void dfs(int v) {
	visited[v] = true;
	for (int i = 0; i < graph[v].size(); i++) {
		int next = graph[v][i];
		if (!visited[next]) {
			cnt++;
			dfs(next);
		}
	}
}
int main() {
	int N, M;
	cin >> N >> M;
	graph.resize(N+1);
	int max = 0;
	vector <int> answer;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
    //단방향 그래프
		graph[b].push_back(a);
	}
	for (int i = 1; i <= N; i++) {
		cnt = 0;
		visited.assign(N + 1, false);
		dfs(i);
		if (cnt > max) {
			answer.clear();
			answer.push_back(i);
			max = cnt;
		}
		else if (cnt == max) {
			answer.push_back(i);
		}
	}
	sort(answer.begin(), answer.end());
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << " ";
	}
}
