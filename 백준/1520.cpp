#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
vector<vector<int>> map;
vector <vector<int>> dp;
typedef pair<int, int> pi;

int dx[4] = { 0, 0,-1, 1 };
int dy[4] = { -1, 1,0, 0 };
int M, N;
int cnt = 0;
int dfs(int x, int y) {
	if (dp[x][y] != -1) return dp[x][y]; //값이 이미 있는 경우
	if (x == M - 1 && y == N - 1) return 1;
	dp[x][y] = 0;
	for (int i = 0; i < 4; i++) {
		int nextX = x + dx[i];
		int nextY = y + dy[i];
		if (nextX < 0 || nextX >= M || nextY < 0 || nextY >= N) continue;
		if (map[nextX][nextY] >= map[x][y]) continue;
		dp[x][y] += dfs(nextX, nextY);
	}
	return dp[x][y];
}
int main() {
	cin >> M >> N;
	map.resize(M, vector<int>(N));
	dp.assign(M, vector<int>(N, -1));
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	cout << dfs(0, 0);
	
}
