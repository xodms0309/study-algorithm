#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M;
vector <vector<int>> ice;
vector<vector<bool>>visited;
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
void dfs(int x, int y) {
	visited[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nextX = x + dx[i];
		int nextY = y + dy[i];
		if (nextX >=1 && nextX < N-1 && nextY >= 1 && nextY < M-1) {
			if (ice[nextX][nextY]>0&&!visited[nextX][nextY]) 
				dfs(nextX, nextY);
		}
	}
}

int main() {
	cin >> N >> M;
	ice.resize(N, vector<int>(M));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> ice[i][j];
		}
	}
	int year = 0;
	while (true) {
		int area = 0;
		visited.assign(N, vector<bool>(M, false));
		for (int i = 1; i < N - 1; i++) {
			for (int j = 1; j < M - 1; j++) {
				if (ice[i][j] > 0 && !visited[i][j]) {
					area++;
					dfs(i, j);
				}
			}
		}
		//다 녹을때까지 분리되지 않는다면
		if (area == 0) {
			year = 0;
			break;
		}
		else if (area >= 2) {
			break;
		}
		//빙하 녹는 부분
		vector <vector<int>> temp(N, vector<int>(M));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				temp[i][j] = ice[i][j];
			}
		}
		for (int i = 1; i < N; i++) {
			for (int j = 1; j < M; j++) {
				int cnt = 0;
				if (temp[i][j] > 0) {
					for (int k = 0; k < 4; k++) {
						int X = i + dx[k];
						int Y = j + dy[k];
						if (X >= 0 && X < N && Y >= 0 && Y < M) {
							if (temp[X][Y] == 0) cnt++;
						}
					}
					ice[i][j] -= cnt;
					if (ice[i][j] < 0) ice[i][j] = 0;
				}
			}
		}
		year++;
	}
	cout << year;
}
