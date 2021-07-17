#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
vector <vector <int>> maze;
vector <vector <bool>> visited;
queue <pair <int, int>> q;
vector <vector <int>> dist;
int N, M;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1, 1, 0, 0 };
int cnt = 0;
void bfs(int x, int y){
	visited[x][y] = true;
	q.push({ x,y }); 
	while (!q.empty()) {
		pair <int, int> current = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int next_x = current.first + dx[i];
			int next_y = current.second + dy[i];
			if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < M) {
				if (!visited[next_x][next_y] && maze[next_x][next_y]) {
					visited[next_x][next_y] = true;
					q.push({ next_x, next_y });
					dist[next_x][next_y] = dist[current.first][current.second] + 1;
				}
			}
		}
	}
}
int main() {
	cin >> N >> M;
	maze.assign(N, vector<int>(M, 0));
	dist.assign(N, vector<int>(M, 0));
	visited.assign(N, vector <bool>(M, false));
	int a, b;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf_s("%1d", &maze[i][j]);
		}
	}
	bfs(0, 0);
	cout << dist[N-1][M-1]+1;

}
