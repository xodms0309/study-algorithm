#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector <vector <int>> island;
vector <vector <bool>> visited;
int dx[8] = { 0,0,-1,1, 1,1,-1,-1 };
int dy[8] = { -1,1,0,0, -1, 1,1,-1 };
int W, H;

void bfs(int x, int y) {
	queue <pair<int, int>> q;
	visited[x][y] = true;
	q.push({ x, y });
	while (!q.empty()) {
		int curX = q.front().first;
		int curY = q.front().second;
		q.pop();
		for (int i = 0; i < 8; i++) {
			int nextX = curX + dx[i];
			int nextY = curY + dy[i];
			if (nextX >= 0 && nextX < H && nextY >= 0 && nextY < W) {
				if (!visited[nextX][nextY]&&island[nextX][nextY]) {
					visited[nextX][nextY] = true;
					q.push({ nextX, nextY });
				}
			}
		}
	}
}
int main() {
	while (true) {
		int cnt = 0;
		cin >> W >> H;
		if (W == 0 && H == 0) break;
		island.assign(H, vector<int>(W));
		visited.assign(H, vector<bool>(W, false));
		//섬 정보
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				scanf_s("%d", &island[i][j]);
			}
		}
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				if (!visited[i][j]&&island[i][j]) {
					bfs(i, j);
					cnt++;
				}
			}
		}
		cout << cnt << "\n";

	}
}
