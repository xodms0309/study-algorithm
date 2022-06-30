#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pi;
vector<vector<bool>> visited;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1, 1, 0, 0 };
int n;
bool isReachable(int x, int y) {
	if (x >= 0 && x < n && y >= 0 && y < n) return true;
	return false;
}

void dfs(vector<vector<int>> &graph, int x, int y, int cnt) {
	visited[x][y] = true;
	graph[x][y] = cnt;
	for (int i = 0; i < 4; i++) {
		int nextX = x + dx[i];
		int nextY = y + dy[i];
		if (!isReachable(nextX, nextY)) continue;
		if (graph[nextX][nextY] && !visited[nextX][nextY]) {
			dfs(graph, nextX, nextY, cnt);
		}
	}
}

int bfs(vector<vector<int>>& graph, int cnt) {
	vector<vector<bool>> visited(n, vector<bool>(n, false));
	queue<pi> q;

	//해당 번호의 섬을 모두 큐에 넣는다
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (graph[i][j] == cnt) {
				q.push({ i, j });
			}
		}
	}
	
	int dist = 0;

	while (!q.empty()) {
		//큐 안에 있는 섬들을 한 번씩 돌림
		int x = q.size();
		for (int i = 0; i < x; i++) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for (int j = 0; j < 4; j++) {
				int nextX = x + dx[j];
				int nextY = y + dy[j];
				if (!isReachable(nextX, nextY)) continue;
				//만약 다른 섬에 도착
				if (graph[nextX][nextY] && graph[nextX][nextY] != cnt) {
					//cout << x << y << nextX << nextY << "\n";
					return dist;
				}
				if (graph[nextX][nextY]==0 && !visited[nextX][nextY]) {
					visited[nextX][nextY] = true;
					q.push({ nextX, nextY });
				}
			}
		}
		dist++;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;

	vector<vector<int>> graph(n, vector<int>(n));
	visited.assign(n, vector<bool>(n, false));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> graph[i][j];
		}
	}

	//섬을 분류하기 (dfs 사용)
	int cnt = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j] && graph[i][j]) {
				dfs(graph, i, j, cnt);
				cnt++;
			}
		}
	}


	int answer = 10001;
	for (int i = 1; i < cnt; i++) {
		answer = min(answer, bfs(graph, i));
	}
	
	cout << answer;
}
