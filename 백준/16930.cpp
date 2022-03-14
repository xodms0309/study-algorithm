#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> pi;
int N, M, K, startX, startY, destX, destY;
vector<vector<char>>graph;
vector<vector<int>>visited;
queue<pair<pi, int>> q;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
void bfs() {
	q.push(make_pair(make_pair(startX,startY),0));
	visited[startX][startY] = 0;
	while (!q.empty()) {
		int currentX = q.front().first.first;
		int currentY = q.front().first.second;
		int dist = q.front().second;
		q.pop();
		if (currentX == destX &&currentY== destY) {
			cout << dist;
			exit(0);
		}
		for (int i = 0; i < 4; i++) {
			//다른 bfs와 달리 k만큼 이동할 수 있어서 for문을 돌려야 함
			for (int k = 1; k <= K; k++) {
				int nextX = currentX + k * dx[i];
				int nextY = currentY + k * dy[i];
				if (nextX >= 1 && nextX <= N && nextY >= 1 && nextY <= M && graph[nextX][nextY] != '#') {
					//방문하지 않은 노드라면 바로 방문하고 큐에 집어 넣음
					if (visited[nextX][nextY] == 1e9) {
						visited[nextX][nextY] = dist + 1;
						q.push(make_pair(make_pair(nextX, nextY),dist+1));
					}
					//이미 방문한 노드 중에 같은 가중치라면 계속해서 탐색
					else if (visited[nextX][nextY] == dist + 1) {
						continue;
					}
					//아니면 그냥 break
					else break;
				}
				//위 조건을 만족하지 않는다면 바로 break해줘야함
				else break;
			}
		}
	}
}
int main() {
	cin >> N >> M >> K;
	graph.assign(N + 1, vector<char>(M + 1));
	visited.assign(N + 1, vector<int>(M + 1));
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> graph[i][j];
			visited[i][j] = 1e9;
		}
	}
	cin >> startX >> startY >> destX >> destY;
	bfs();
	cout << -1;
}
