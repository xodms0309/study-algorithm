#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> paper;
vector <vector<bool>> visited;
vector<int> area;
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
int M, N, K;
int cnt = 0;
void dfs(int x, int y) {
	visited[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nextX = x + dx[i];
		int nextY = y + dy[i];
		if (nextX >= 0 && nextX < M && nextY >= 0 && nextY < N) {
			if (!visited[nextX][nextY] && !paper[nextX][nextY]) {
				cnt++;
				dfs(nextX, nextY);
			}
		}
	}
}
int main() {
	cin >> M >> N >> K;
	paper.resize(M, vector<int>(N, 0));
	visited.assign(M, vector<bool>(N, false));
	int x1, x2, y1, y2;
	for (int i = 0; i < K; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		for (int y = M - y2; y < M - y1; y++) {
			for (int x = x1; x < x2; x++) {
				paper[y][x] = 1;
			}
		}
	}
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j] && !paper[i][j]) {
				cnt = 1;
				dfs(i, j);
				area.push_back(cnt);
			}
		}
	}
	sort(area.begin(), area.end());
	cout << area.size()<<"\n";
	for (int i = 0; i < area.size(); i++) {
		cout << area[i] << " ";
	}
}
