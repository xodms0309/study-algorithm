#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 100001
using namespace std;
int N, K;
int l; //체스판의 한 변의 길이
vector <vector <int>> chess;
vector <vector <bool>> visited;
vector <vector <int>> arr;

int dx[8] = { 2, 2, 1, 1, -1, -1, -2, -2 };
int dy[8] = { 1, -1, 2, -2,2,-2,1,-1 };
int cnt = 0;
int bfs(int startX, int startY, int destX, int destY) {
	queue <pair <int, int>>q;
	visited[startX][startY] = true;
	q.push({ startX, startY });
	while (!q.empty()) {
		int curX = q.front().first;
		int curY = q.front().second;
		q.pop();
		if (curX == destX && curY == destY) return arr[destX][destY];
		for (int i = 0; i < 8; i++) {
			int nextX = curX + dx[i];
			int nextY = curY + dy[i];
			if (nextX >= 0 && nextX < l && nextY >= 0 && nextY < l) {
				if (!visited[nextX][nextY]) {
					visited[nextX][nextY] = true;
					q.push({ nextX, nextY });
					arr[nextX][nextY] = arr[curX][curY] + 1;
				}
			}
		}
	}
}
int main() {
	int T; //테스트 케이스 수
	cin >> T;
	while(T--) {
		cin >> l;
		chess.resize(l);
		visited.assign(l, vector<bool>(l, false));
		arr.assign(l, vector<int>(l, 0));
		int startX, startY;
		cin >> startX >> startY;
		int destX, destY;
		cin >> destX >> destY;
		cout <<bfs(startX, startY, destX, destY) <<"\n";
	}
	

}
