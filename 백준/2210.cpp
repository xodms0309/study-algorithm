#include <iostream>
#include <vector>
#include <set>
#include <string>
using namespace std;
int dx[4] = { 0,1,-1,0 };
int dy[4] = { 1,0,0,-1 };
vector<vector<int>>graph;
set<int>answer;
void dfs(int x, int y, int num, int cnt) {
	for (int i = 0; i < 4; i++) {
		int nextX = x + dx[i];
		int nextY = y + dy[i];
		if (cnt == 6) {
			answer.insert(num);
			return;
		}
		if (nextX >= 0 && nextX < 5 && nextY >= 0 && nextY < 5) {
			dfs(nextX, nextY, num*10+graph[nextX][nextY], cnt+1);
		}
	}
}
int main() {
	graph.assign(5, vector<int>(5));
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> graph[i][j];
		}
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			dfs(i, j, graph[i][j], 1);
		}
	}
	cout << answer.size();
}
