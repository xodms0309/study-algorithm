/*
vector을 파라미터로 사용할 때
&v는 공유
v는 값만 복사
이거 때문에 1시간 헤맸다 ...
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, M; //세로, 가로
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int answer = 0;
void bfs(vector<vector<int>> v) {
	queue <pair<int, int>> q;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (v[i][j] == 2) {
				q.push({ i, j });
			}
		}
	}
	while (!q.empty()) {
		int curX = q.front().first;
		int curY = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nextX = curX + dx[i];
			int nextY = curY + dy[i];
			if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < M) {
				if (v[nextX][nextY] == 0) {
					v[nextX][nextY] = 2;
					q.push({ nextX, nextY });
				}
			}
		}
	}
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (v[i][j] == 0) cnt++;
		}
	}
	answer = max(answer, cnt);
}
void makeWall(vector<vector<int>> v,int x, int y,int wall) {
	v[x][y] = 1;
	if (wall == 3) {
		bfs(v);
		return;
	}
	for (int i = x; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (v[i][j]==0) {
				makeWall(v, i, j,wall + 1);
			}
		}
	}
}

int main() {
	cin >> N >> M;
	vector <vector<int>> virus;
	virus.assign(N, vector<int>(M,0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf_s("%d", &virus[i][j]);
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (virus[i][j] == 0) {
				makeWall(virus, i, j, 1);
			}
		}
	}
	cout << answer;
}
