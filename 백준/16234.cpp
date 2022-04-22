#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pi;
typedef vector<vector<int>> vi;
typedef vector<vector<bool>> vb;
int N, L, R;	
int cnt, total;
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1,1,0,0 };
void dfs(vi&country, vb&visited, vector<pi> &v, int x, int y) {
	for (int i = 0; i < 4; i++) {
		int nextX = x + dx[i];
		int nextY = y + dy[i];
		if (nextX < 0 || nextY < 0 || nextX >= N || nextY >= N) continue;
		int dist = abs(country[x][y] - country[nextX][nextY]);
		if (dist >= L && dist <= R && !visited[nextX][nextY]) {
			visited[nextX][nextY] = true;
			v.push_back({ nextX, nextY });
			cnt++;
			total += country[nextX][nextY];
			dfs(country, visited, v, nextX, nextY);
		}
	}
}
void move(vector<pi>&v, vi &country) {
	for (int i = 0; i < v.size(); i++) {
		country[v[i].first][v[i].second] = total / cnt;
	}
}
int main() {
	cin >> N >> L >> R;
	vi country(N, vector<int>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> country[i][j];
		}
	}
	int answer = 0;
	while (true) {
		bool flag = false;
		vb visited(N, vector<bool>(N, false));
		vector<pi> v;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (visited[i][j]) continue;
				visited[i][j] = true;
				cnt = 1;
				total = country[i][j];
				v.push_back({ i, j });
				dfs(country, visited, v, i,j);
				if (cnt >= 2) {
					flag = true;
					move(v, country);
				}
				v.clear();
			}
		}
		if (!flag) break;
		else answer++;
	}
	cout << answer;
}
