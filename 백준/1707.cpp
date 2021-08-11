#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>>graph;
vector<int> color;	
int V, E;
void dfs(int start, int c) {
	color[start] = c;
	for (int i = 0; i < graph[start].size(); i++) {
		int next = graph[start][i];
		if (color[next]==0) 
			dfs(next, 3 - c);
	}
}
bool isBigraph() {
	for (int i = 1; i <=V; i++) {
		for (int j = 0; j < graph[i].size(); j++) {
			int next = graph[i][j];
			if (color[i] == color[next]) return false;
		}
	}
	return true;
}
int main() {
	int T;
	cin >> T;
	while (T--) {
		cin >> V >> E;
		graph.assign(20001, vector<int>(0, 0));
		color.assign(20001, 0);
		for (int i = 0; i < E; i++) {
			int v1, v2;
			cin >> v1 >> v2;
			graph[v1].push_back(v2);
			graph[v2].push_back(v1);
		}
		for (int i = 1; i <= V; i++) {
			if (color[i]==0) dfs(i, 1);
		}
		if (isBigraph()) cout << "YES\n";
		else cout << "NO\n";
	}
}
