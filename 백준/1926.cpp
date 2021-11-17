#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
vector<vector<int>>picture;
vector <vector<bool>> visited;
queue<pair<int, int>> q;
int N, M;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = {0, 0, -1, 1};
int MAX_CNT = 0;
int cnt = 0;
int area = 0;
void bfs(int x, int y) {
	visited[x][y] = true;
	q.push({ x,y });
	while (!q.empty()) {
		area++;
		pair <int, int> current = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nextX = current.first + dx[i];
			int nextY = current.second + dy[i];
			if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < M) {
				if (!visited[nextX][nextY] && picture[nextX][nextY]) {
					visited[nextX][nextY] = true;
					q.push({ nextX, nextY });
				}
			}
		}
	}
}
int main() {
	cin >> N >> M;
	picture.assign(N, vector<int>(M));
	visited.assign(N, vector<bool>(M, false));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> picture[i][j];
		}
	}
	int answer=0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!visited[i][j]&&picture[i][j]) {
				area = 0;
				bfs(i, j);
				cnt++;
				answer = max(answer, area);
			}
		}
	}
	cout << cnt<<"\n"<<answer;
}
