#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
vector <vector <int>> tomato;
queue <pair <int, int>> q;

int dx[4] = { 0,0,-1, 1 };
int dy[4] = { -1, 1, 0, 0 };
int N, M;
int cnt = 0;
void bfs() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (tomato[i][j] == 0) cnt++; //안 익은 토마토 수
			else if (tomato[i][j] == 1) q.push({i, j });
		}
	}
	pair <int, int> current;
	while (!q.empty()) { 
		current= q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int next_x = current.first + dx[i];
			int next_y = current.second + dy[i];
			if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < M) {
				if (!tomato[next_x][next_y]) {
					cnt--;
					tomato[next_x][next_y] = tomato[current.first][current.second]+1;
					q.push({ next_x, next_y });
				}
			}
		}
	}
	if (cnt == 0) cout << tomato[current.first][current.second] - 1;
	else cout << -1;
}
int main() {
	cin >> M >> N;
	tomato.assign(N, vector<int>(M, 0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf_s("%d", &tomato[i][j]);
		}
	}
	bfs();
}
