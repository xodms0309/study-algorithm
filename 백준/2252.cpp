#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> topologicalSort(int n, vector<vector<int>> &graph, vector<int> &indegree) {
	queue<int> q;
	vector<int> result;
	for (int i = 1; i <=n; i++) {
		if (indegree[i] == 0) q.push(i);
	}
	while (!q.empty()) {
		int current = q.front();
		q.pop();
		result.push_back(current);
		for (int i = 0; i < graph[current].size(); i++) {
			int next = graph[current][i];
			indegree[next]--;
			if (indegree[next] == 0) {
				q.push(next);
				
			}
		}
	}
	return result;
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> graph(n + 1, vector<int>(0));
	vector<int> indegree(n + 1, 0);
	vector<int> result;
	while (m--) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		indegree[b]++;
	}

	result= topologicalSort(n, graph, indegree);
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}

}
