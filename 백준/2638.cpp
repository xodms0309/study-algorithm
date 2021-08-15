#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int N, M;
vector <vector<int>> cheese;
vector<vector<bool>>visited;
queue <pair<int, int>>q;
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

void bfs() {
	pair <int, int> current;
	visited[0][0] = true;
	q.push({ 0,0 });
	while (!q.empty()) {
		current = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nextX = current.first + dx[i];
			int nextY = current.second + dy[i];
			if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < M) {
				if (cheese[nextX][nextY]==0&&!visited[nextX][nextY]) {
					visited[nextX][nextY] = true;
					q.push({nextX,nextY });
				}
			}
		}
	}
}
void melt() {
	vector <vector<int>>temp(N, vector<int>(M));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			temp[i][j]= cheese[i][j];
		}
	}
	for (int i = 1; i < N; i++) {
		for (int j = 1; j < M; j++) {
			int cnt = 0;
			if (temp[i][j]) {
				for (int k = 0; k < 4; k++) {
					int X = i + dx[k];
					int Y = j + dy[k];
					if (X >= 0 && X < N && Y >= 0 && Y < M) {
						if (temp[X][Y]==0&&visited[X][Y]) 
							cnt++;
					}
				}
				if (cnt >= 2) cheese[i][j] -= 1;
			}
		}
	}
}
int main() {
	cin >> N >> M;
	cheese.resize(N, vector<int>(M));
	int cheeseCnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> cheese[i][j];
		}
	}
	int time = 0;
	while (true){
		visited.assign(N, vector<bool>(M, false));
		bfs();
		melt();
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (cheese[i][j]) cheeseCnt++;
			}
		}		
		time++;
		if (cheeseCnt == 0) break;
		cheeseCnt = 0;
	}
	cout << time;
}
