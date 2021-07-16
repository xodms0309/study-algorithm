#include <iostream>
#include <vector>
using namespace std;
vector <vector <int>> graph;
vector <vector <bool>> visited;
int M, N, K; //가로, 세로, 배추 개수
int dx[4] = {0, 0, -1, 1};
int dy[4] = { -1, 1, 0, 0 };
int cnt = 0;
void dfs(int x, int y) {
	visited[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int next_x = x + dx[i];
		int next_y = y + dy[i];
		if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < M) {
			if (graph[next_x][next_y] && !visited[next_x][next_y]) {
				dfs(next_x, next_y);
			}
		}
	}
}
int main() {
	int T; //테스트 케이스 수
	cin >> T;
	while (T--) {
		cin >> M >> N >> K;
		graph.assign(N , vector<int>(M , 0));
		visited.assign(N , vector<bool>(M , false));
		for (int i = 0; i < K; i++) {
			int a, b;
			cin >> a >> b;
			graph[b][a] = 1;
		}
		cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (graph[i][j] && !visited[i][j]) {
					dfs(i, j);
					cnt++;
				}
			}
		}
		cout << cnt<<"\n";
	}

}
