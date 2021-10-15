#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>>friends;
vector <bool>visited;
void dfs(int v) {
	for (int i = 0; i < friends[v].size(); i++) {
		int next = friends[v][i];
		visited[next] = true;
		if (v==1) {
			dfs(next);
		}
	}
}
int main() {
	int N, M;
	int cnt = 0;
	cin >> N >> M;
	friends.resize(N + 1);
	visited.assign(N + 1, false);
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		friends[a].push_back(b);
		friends[b].push_back(a);
	}
	dfs(1);
	for (int i = 2; i <= N; i++) {
		if (visited[i]) cnt++;
	}
	cout << cnt;
}
