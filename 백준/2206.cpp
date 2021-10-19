#include <iostream>
#include <vector>
#include <queue>
#define MAX 1000
using namespace std;
vector <vector<int>> graph;
bool visited[MAX][MAX][2] = { false, };
int dx[4]= { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
int N, M;
int bfs() {
	queue<pair<pair<int, int>, pair<int, int>>> q;
	visited[0][0][1] = true;
	q.push({ { 0,0 }, { 1,1 } });
	while (!q.empty()) {
		pair <int, int> current = q.front().first;
		int wall = q.front().second.first;
		int cnt = q.front().second.second;
		q.pop();
		if (current.first == N-1 && current.second == M-1) {
			return cnt;
		}
		for (int i = 0; i < 4; i++) {
			int nextX = current.first + dx[i];
			int nextY = current.second + dy[i];
			if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < M) {
				if (graph[nextX][nextY] == 1 && wall == 1) {
					visited[nextX][nextY][wall] = true;
					q.push({ {nextX, nextY}, {wall - 1, cnt + 1} });
				}
				if (!visited[nextX][nextY][wall] && graph[nextX][nextY] == 0) {
					visited[nextX][nextY][wall] = true;
					q.push({ { nextX, nextY } ,{wall, cnt + 1} });
				}
			}
		}
	}
	return -1;
}

int main() {
	cin >> N >> M;
	graph.resize(N, vector<int>(M));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf_s("%1d", &graph[i][j]);
		}
	}
	cout << bfs();
}
