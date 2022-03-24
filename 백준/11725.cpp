#include <iostream>
#include <vector>
const int MAX = 100001;
using namespace std;
vector<int> parent(MAX);
vector<bool>visited;
//vector<vector<int>>로 선언하면 메모리 초과남
vector<int> v[MAX];
void dfs(int node) {
	visited[node] = true;
	for (int i = 0; i < v[node].size(); i++) {
		int next = v[node][i];
		if (!visited[next]) {
			parent[next] = node;
			dfs(next);
		}
	}
}
int main() {
	int N;
	cin >> N;
	visited.assign(N + 1, false);
	for (int i = 0; i < N-1; i++) {
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1);
	for (int i = 2; i <= N; i++) {
		cout << parent[i] << "\n";
	}
}

