#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef pair<int, int> pi;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int main() {
	int r, c, t;
	cin >> r >> c >> t;
	vector<vector<int>> graph(r, vector<int>(c, 0));
	vector<int> air;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> graph[i][j];
			if (graph[i][j] == -1) {
				air.push_back(i);
			}
		}
	}

	//확산
	while (t--) {
		vector<vector<int>> spread_copy(r, vector<int>(c, 0));
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (graph[i][j]==0 || graph[i][j] == -1) continue;
				int spread = graph[i][j] / 5;
				int cnt = 0;
				for (int d = 0; d < 4; d++) {
					int nextX = i + dx[d];
					int nextY = j + dy[d];
					if (nextX < 0 || nextX >= r || nextY < 0 || nextY >= c) continue;
					if (graph[nextX][nextY] == -1) continue;
					spread_copy[nextX][nextY] += spread;
					cnt++;
				}
				int left = graph[i][j] - (spread * cnt);
				spread_copy[i][j] += left;
			}
		}

		graph = spread_copy;

		vector<vector<int>> air_copy(r, vector<int>(c, 0));
		air_copy = graph;
		int first = air[0];
		int second = air[1];
		//옆으로 가는 공기
		for (int i = 0; i < c-1; i++) {
			air_copy[first][i+1] = graph[first][i];
			air_copy[second][i + 1] = graph[second][i];
		}		
		for (int i = c - 1; i > 0; i--) {
			air_copy[0][i-1] = graph[0][i];
			air_copy[r-1][i-1] = graph[r-1][i];
		}

		//올라가는 공기
		for (int i = first; i > 0; i--) {
			air_copy[i-1][c - 1] = graph[i][c - 1];
		}		
		for (int i = r - 1; i > second; i--) {
			air_copy[i-1][0] = graph[i][0];
		}

		//내려가는 공기
		for (int i = 0; i < first; i++) {
			air_copy[i+1][0] = graph[i][0];
		}
		for (int i = second; i < r - 1; i++) {
			air_copy[i+1][c - 1] = graph[i][c - 1];
		}

		graph = air_copy;
		graph[first][0] = -1;
		graph[second][0] = -1;

	}

	
	int answer = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (graph[i][j] == -1) continue;
			answer += graph[i][j];
		}
	}
	cout << answer;

}

