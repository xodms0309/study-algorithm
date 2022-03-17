#include <iostream>
#include <vector>
#include <deque>
#include <map>
using namespace std;
int dx[4] = { 0,-1,0,1 };
int dy[4] = { 1,0,-1,0 };
typedef pair<int, int> pi;
vector<vector<int>> board(101, vector<int>(101));
map <int, char> dir;
int play(int N) {
	deque<pi> snake;
	snake.push_back({ 0,0 });
	board[0][0] = 1;//뱀이 있는 곳
	int t = 0, head=0;
	while (true) {
		t++;
		int nextX = snake.front().first + dx[head];
		int nextY = snake.front().second + dy[head];
		//벽이나 자기 몸에 부딛히지 않았을 때
		if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= N || board[nextX][nextY] == 1) break;
			//사과가 없다면
		if (board[nextX][nextY] != 2) {
			//꼬리 줄이기
			board[snake.back().first][snake.back().second] = 0;
			snake.pop_back();
		}
		//몸 늘이기
		snake.push_front({ nextX, nextY });
		board[nextX][nextY] = 1;
		if (dir[t] == 'L') head = (head + 1) % 4;
		if (dir[t] == 'D') head = (head + 3) % 4;
	}
	return t;
}
int main() {
	int N, K, L;
	cin >> N;
	cin >> K;
	for (int i = 0; i < K; i++) {
		int x, y;
		cin >> x >> y;
		board[x - 1][y - 1] = 2; //사과가 있는 곳
	}
	cin >> L;
	for (int i = 0; i < L; i++) {
		int t; char r;
		cin >> t >> r;
		dir[t] = r;
	}
	cout << play(N);
}

