#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int, int> pi;
const int INF = 1e9;

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> graph(n+1);
	vector<vector<int>> dist(n + 1, vector<int>(n + 1, INF));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) dist[i][j] = 0;
		}
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);

		dist[a][b] = 1;
		dist[b][a] = 1;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (dist[i][j] > dist[i][k] + dist[k][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}

	int answer = INF;
	int idx = 0;
	for (int i = 1; i <= n; i++) {
		int sum = 0;
		for (int j = 1; j <= n; j++) {
			sum += dist[i][j];
		}
		if (answer > sum) {
			idx = i;
			answer = sum;
		}
	}
	cout << idx;

	
}
