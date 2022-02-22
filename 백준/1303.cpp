#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;	
int N, M;
vector <vector <char>> graph;
vector <vector <bool>> visited;
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
int cnt = 0;
int blue = 0;
int white = 0;
void dfs(int x, int y) {
	visited[x][y] = true;
	cnt++;
	for (int i = 0; i < 4; i++) {
		int nextX = x + dx[i];
		int nextY = y+ dy[i];
		if (nextX >= 0 && nextX < M && nextY >= 0 && nextY< N&&!visited[nextX][nextY]) {
			if (graph[nextX][nextY] ==graph[x][y]) {
				dfs(nextX, nextY);
			}
		}
	}
}

int main() {
	cin >> N >> M;
	graph.assign(M, vector<char>(N));
	visited.assign(M, vector<bool>(N, false));
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> graph[i][j];
		}
	}
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cnt = 0;
			if (!visited[i][j]) {
				dfs(i, j);
				if (graph[i][j] == 'W') white += cnt * cnt;
				else blue += cnt * cnt;
			}
		}
	}
	cout << white <<  " " << blue;
}
