#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int INF = 1e10;
typedef pair<int, int> pi;

int dijkstra(vector<vector<pi>> &bus, int n, int start, int end) {
	priority_queue<pi, vector<pi>, greater<>> pq;	
	vector<int> dist(n + 1, INF);
	pq.push({ 0, start });
	dist[start] = 0;
	while (!pq.empty()) {
		int cost = pq.top().first;
		int current = pq.top().second;
		pq.pop();

		if (cost > dist[current]) continue;

		for (int i = 0; i < bus[current].size(); i++) {
			int next = bus[current][i].first;
			int next_cost = bus[current][i].second+cost;

			if (next_cost < dist[next]) {
				dist[next] = next_cost;
				pq.push({ next_cost, next });
			}
		}
	}
	return dist[end];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<vector<pi>> bus(n + 1, vector<pi>(0));

	while (m--) {
		int a, b, cost;
		cin >> a >> b >> cost;
		bus[a].push_back({ b,cost });
	}
	int start, end;
	cin >> start >> end;
	cout << dijkstra(bus, n, start, end);

	//cout << dist[end];
}
