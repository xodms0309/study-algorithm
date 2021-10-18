#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int A, B;
vector <vector<char>> map;
vector <vector <bool>> visited;
vector <vector<int>> dist;
int dx[4]= { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
int N, M;
int max_num = 0;
void bfs(int x, int y) {
	visited[x][y] = true;
	queue<pair <int, int>> q;
	q.push({ x, y });
	while (!q.empty()) {
		pair <int, int> current = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nextX = current.first + dx[i];
			int nextY = current.second + dy[i];
			if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < M) {
				if (!visited[nextX][nextY] && map[nextX][nextY] == 'L') {
					visited[nextX][nextY] = true;
					q.push({ nextX, nextY });
					dist[nextX][nextY] = dist[current.first][current.second]+1;
					max_num = max(max_num, dist[nextX][nextY]);
				}
			}
		}
	}
}

int main() {
	cin >> N >> M;
	map.resize(N, vector<char>(M));
	visited.assign(N, vector<bool>(false, M));
	dist.assign(N, vector<int>(M, 0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 'L') {
				visited.assign(N, vector<bool>(M, false));
				dist.assign(N, vector<int>(M, 0));
				bfs(i, j);
			}
		}
	}
	cout << max_num;
}
