#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> graph;
vector<vector<bool>> visited;
int answer = 0;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };	
int n, m;
bool isReachable(int x, int y) {
	if (x < 0 || x >= n || y < 0 || y >= m) return false;
	return true;
}

void dfs(int x, int y, int depth, int sum) {
	if (depth == 3) {
		answer = max(answer, sum);
		return;
	}
	for (int i = 0; i < 4; i++) {
		int nextX = x + dx[i];
		int nextY = y + dy[i];
		if (!isReachable(nextX, nextY)) continue;
		if (visited[nextX][nextY]) continue;
		visited[nextX][nextY] = true;
		dfs(nextX, nextY, depth + 1, sum + graph[nextX][nextY]);
		visited[nextX][nextY] = false;
	}
}

void shape1(int x, int y) {
	int sum = 0;
	sum = graph[x][y] + graph[x][y + 1] + graph[x][y + 2] + graph[x + 1][y + 1];
	answer = max(sum, answer);
}

void shape2(int x, int y) {
	int sum = 0;
	sum = graph[x + 1][y] + graph[x + 1][y + 1] + graph[x][y+1] + graph[x + 1][y + 2];
	answer = max(sum, answer);
}

void shape3(int x, int y) {
	int sum = 0;
	sum = graph[x][y] + graph[x + 1][y] + graph[x + 2][y] + graph[x + 1][y + 1];
	answer = max(sum, answer);
}

void shape4(int x, int y) {
	int sum = 0;
	sum = graph[x + 1][y] + graph[x][y + 1] + graph[x + 1][y + 1] + graph[x + 2][y + 1];
	answer = max(sum, answer);
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	graph.assign(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> graph[i][j];
		}
	}

	visited.assign(n, vector<bool>(m, false));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visited[i][j] = true;
			dfs(i, j, 0, graph[i][j]);
			visited[i][j] = false;
			if (i + 1 < n && j + 2 < m) shape1(i, j);
			if (i + 1 < n && j + 2 < m) shape2(i, j);
			if (i + 2 < n && j + 1 < m) shape3(i, j);
			if (i + 2 < n && j + 1 < m) shape4(i, j);
		}
	}
	cout << answer;
}
