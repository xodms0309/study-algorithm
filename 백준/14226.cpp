#include <iostream>
#include <vector>
#include <queue>
using namespace std;	
int S=0;
int bfs() {
	vector <vector<bool>> visited(2000, vector<bool>(2000,false)); // visited[a][b]=> 화면에 a개, 클립보드에 b개
	visited[1][0] = true;
	queue<pair<pair<int, int>, int> > q;
	q.push(make_pair(make_pair(0,1), 0));
	while (!q.empty()) {
		int clip = q.front().first.first;
		int current = q.front().first.second;
		int time = q.front().second;
		q.pop();

		if (current == S) return time;

		//화면에 있고 최대값보다 작을 때
		if (current > 0 && current < 2000) {
			//화면에 있는 만큼 복사
			if (!visited[current][current]) {
				visited[current][current] = true;
				q.push(make_pair(make_pair(current, current), time + 1));
			}
			//하나 삭제
			if (!visited[current - 1][clip]) {
				visited[current - 1][clip] = true;
				q.push(make_pair(make_pair(clip, current - 1), time + 1));
			}
		}
		//클립보드에 있을 때
		if (clip > 0 && clip + current < 2000) {
			if (!visited[clip + current][clip]) {
				visited[clip + current][clip] = true;
				q.push(make_pair(make_pair(clip, current + clip), time + 1));
			}
		}
	}
	return 0;
}
int main() {
	cin >> S;
	cout<<bfs();
}
