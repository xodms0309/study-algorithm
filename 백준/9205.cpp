#include <iostream>
#include <vector>
#include <queue>
#include<cmath>
using namespace std;
typedef pair<int, int> pi;		
vector<pi> v;
vector<bool>visited;
pi house;
pi festival;
void bfs(int N, int x, int y) {
	queue<pi>q;
	q.push({ x, y });
	while (!q.empty()) {
		int currentX = q.front().first;
		int currentY = q.front().second;
		q.pop();
		//맥주 20개로 갈 수 있다면
		if (abs(festival.first - currentX) + abs(festival.second - currentY) <= 1000) {
			cout << "happy";
			return;
		}
		else {
			for (int i = 0; i < N; i++) {
				if (abs(currentX - v[i].first) + abs(currentY - v[i].second) <= 1000) {
					if (!visited[i]) {
						visited[i] = true;
						q.push({ v[i].first, v[i].second });
					}
				}
			}
		}
	}
	cout << "sad";
}
int main() {
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		v.assign(N, { 0,0 });
		visited.assign(N, false);
		cin >> house.first >> house.second;
		for (int i = 0; i < N; i++) {
			cin >> v[i].first >> v[i].second;
		}
		cin >> festival.first >> festival.second;
		bfs(N, house.first, house.second);
		cout << "\n";
	}
}

