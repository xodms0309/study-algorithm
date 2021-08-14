#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
vector <vector<int>> bamboo;
vector<vector<bool>>visited;
vector <vector<int>> DP; //DP[i][j]=k일 때 판다가 (i,j)에서 k일 살 수 있다는 뜻
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
int answer = 0;
int dfs(int x, int y) {
	if (DP[x][y]) return DP[x][y]; //값이 존재한다면 이미 최대값을 구했으므로 바로 리턴
	DP[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int nextX = x + dx[i];
		int nextY = y + dy[i];
		if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < N) {
			if (bamboo[nextX][nextY] > bamboo[x][y]) {
					DP[x][y]=max(DP[x][y],dfs(nextX, nextY)+1);
				}
			}
		}
	return DP[x][y];
}

int main() {
	cin >> N;
	DP.resize(N, vector<int>(N, 0));
	bamboo.resize(N, vector<int>(N));
	visited.assign(N, vector<bool>(N, false));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> bamboo[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			answer= max(answer,dfs(i, j));
		}
	}
	cout << answer;
}
