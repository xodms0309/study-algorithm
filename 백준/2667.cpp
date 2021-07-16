#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <vector <int>> map;
vector <vector <bool>> visited;
int N; //가로 세로 길이
int dx[4] = {0, 0, -1, 1};
int dy[4] = { -1, 1, 0, 0 };
int cnt = 0;
//int house = 0;
vector <int> house;
void dfs(int x, int y) {
	visited[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int next_x = x + dx[i];
		int next_y = y + dy[i];
		if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < N) {
			if (map[next_x][next_y] && !visited[next_x][next_y]) {
				dfs(next_x, next_y);
				cnt++;
			}
		}
	}
}
int main() {
	cin >> N;
	map.assign(N, vector<int>(N, 0));
	visited.assign(N, vector<bool>(N, false));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf_s("%1d", &map[i][j]);
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] && !visited[i][j]) {
				dfs(i, j);
				house.push_back(cnt);
				cnt = 0;
			}
		}
	}
	cout << house.size()<<"\n";
	sort(house.begin(), house.end());
	for (int i = 0; i < house.size(); i++) {
		cout << house[i]+1 << "\n";
	}
}
