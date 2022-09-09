#include <iostream>
#include <vector>

using namespace std;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> graph(n, vector<int>(n, 0));
	int x, y;
	x = n / 2; y = n / 2;
	int cnt = 1;
	int current = 1;
	int dir = 0;
	while (cnt <= n * n) {
		for (int i = 0; i < current; i++) {
			graph[x][y] = cnt++;
			x += dx[dir];
			y += dy[dir];
		}
		dir = (dir + 1) % 4;
		if (dir % 2 == 0) current++;
	}

	pair<int, int> answer;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (graph[i][j] == m) answer = { i + 1, j + 1 };
			cout << graph[i][j] << " ";
		}
		cout << "\n";
	}
	cout << answer.first << " " << answer.second;
}

