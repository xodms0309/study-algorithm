#include <iostream>
#include <vector>
using namespace std;
vector <vector <int>> network;
vector <bool> visited;
int cnt=0;
void dfs(int v) {
	visited[v] = true;
	for (int i = 0; i < network[v].size(); i++) {
		int next = network[v][i];
		if (!visited[next]) {
			dfs(next);
			cnt++;
		}
	}
}
int main() {
	int n; //컴퓨터 수
	int e; //간선 수
	cin >> n >> e;
	int v1, v2;
	network.resize(n + 1);
	for (int i = 0; i < e; i++) {
		cin >> v1 >> v2;
		network[v1].push_back(v2);
		network[v2].push_back(v1);
	}
	visited = vector<bool>(n + 1, false);
	dfs(1);
	cout << cnt;

}
