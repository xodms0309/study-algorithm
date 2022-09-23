#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
//아래, 오른쪽, 대각선 이동 가능
int dx[3] = { 1, 0, 1 };
int dy[3] = { 0, 1, 1 };

int n, answer = 0;

void dfs(int x, int y, int dir, vector<vector<int>> &graph) {
	if (x == n - 1 && y == n - 1) {
		answer++;
		return;
	}
	for (int i = 0; i < 3; i++) {
		//가로->세로, 세로->가로 불가능
		if (dir == 0 && i == 1) continue;
		if (dir == 1 && i == 0) continue;
		int nextX = x + dx[i];
		int nextY = y + dy[i];
		if (nextX < 0 || nextX >= n || nextY < 0 || nextY >= n) continue;
		if (graph[nextX][nextY] == 1) continue;
		if (i == 2) {
			if (graph[nextX][y] || graph[x][nextY]) continue;
		}
		dfs(nextX, nextY, i,  graph);
	}
}

int main() {
	cin >> n;
	vector<vector<int>> graph(n, vector<int>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> graph[i][j];
		}
	}
	dfs(0, 1, 1, graph);
	cout << answer;
}

