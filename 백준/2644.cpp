#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector <vector <int>> family;
vector <bool> visited;
vector <int> arr;
queue <int> q;

void bfs(int start) {
	visited[start] = true;
	q.push(start);
	while (!q.empty()) {
		int front = q.front();
		q.pop();
		for (int i = 0; i < family[front].size(); i++) {
			int next = family[front][i];
			if (!visited[next]) {
				visited[next] = true;
				q.push(next);
				arr[next] = arr[front] + 1;
			}
		}
	}
}
int main() {
	int n; //사람 수
	int a, b; //두 사람
	int parent, child; //부모, 자식
	int m; //관계의 개수
	cin >> n;
	cin >> a >> b;
	cin >> m;
	family.resize(n + 1);
	visited.assign(n+1, false);
	arr.assign(n + 1, 0);
	for (int i = 0; i < m; i++) {
		cin >> parent >> child;
		family[parent].push_back(child);
		family[child].push_back(parent);
	}
	bfs(a);
	if (arr[b] == 0) cout << -1;
	else cout << arr[b];
}
