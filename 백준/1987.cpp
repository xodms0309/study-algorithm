#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int R, C;
vector<vector<char>> board;
vector<char> alphabet;
vector <vector<bool>> visited;
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
int answer = 1;
void dfs(int x, int y, int cnt) {
	for (int i = 0; i < 4; i++) {
		int nextX = x + dx[i];
		int nextY = y + dy[i];
		if (nextX >= 0 && nextX < R && nextY >= 0 && nextY < C) {
			auto isfound = find(alphabet.begin(), alphabet.end(), board[nextX][nextY]);
			if (!visited[nextX][nextY] && isfound == alphabet.end()) {
				visited[nextX][nextY] = true;
				alphabet.push_back(board[nextX][nextY]);
				dfs(nextX, nextY, cnt+1);
				visited[nextX][nextY] = false;
				alphabet.pop_back();
			}
		}
	}
	if (cnt > answer) answer = cnt;
}
int main() {
	cin >> R >> C;
	board.resize(R, vector<char>(C));
	visited.assign(R, vector<bool>(C, false));
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> board[i][j];
		}
	}
	visited[0][0] = true;
	alphabet.push_back(board[0][0]);
	dfs(0, 0, 1);
	cout << answer;
}
