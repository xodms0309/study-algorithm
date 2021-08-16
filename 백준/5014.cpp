#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int F, S, G, U, D;
vector <bool> visited;
vector <int> stairs;
queue <int> q;
int dx[2];
int cnt = 0;
void bfs(int S) {
	visited[S] = true;
	q.push(S);
	while (!q.empty()) {
		int current = q.front();
		q.pop();
		for (int i = 0; i < 2; i++) {
			int next = current + dx[i];
			if (next > 0 && next <= F) {
				if (!visited[next]) {
					q.push(next);
					visited[next] = true;
					stairs[next] = stairs[current] + 1;
				}
			}
		}
	}
}

int main() {
	cin >> F >> S >> G >> U >> D;
	visited.assign(F+1, false);
	stairs.resize(F + 1);
	dx[0] = U;
	dx[1] = D * (-1);
	bfs(S);
	if (visited[G]) cout << stairs[G];
	else cout << "use the stairs";
}
