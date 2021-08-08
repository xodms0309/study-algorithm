#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
vector<vector<int>> map;
vector <vector<bool>> visited;
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
void dfs(int i, int j, int height) {
	visited[i][j] = true;
	for (int k = 0; k < 4; k++) {
		int nextX = i + dx[k];
		int nextY = j + dy[k];
		if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < N) {
			if (map[nextX][nextY] > height && !visited[nextX][nextY]) {
				dfs(nextX, nextY, height);
			}
		}

	}
}
int main() {
	cin >> N;
	map.resize(N, vector<int>(N));
	int maxHeight = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] > maxHeight) maxHeight = map[i][j];
		}
	}
	int answer = 0;
	for (int h=0; h<maxHeight; h++) {	
		int cnt = 0;
		visited.assign(N, vector<bool>(N, false));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!visited[i][j]&&map[i][j]>h) {
					cnt++;
					dfs(i, j, h);
				}
			}
		}
		if (cnt > answer) answer = cnt;
	}
	cout << answer;
}
