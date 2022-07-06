#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int, int> pi;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int n;
struct seat_info {
	int x;
	int y;
	int empty=0;
	int friends=0;
	bool operator<(const seat_info& s) const {
		//1. 인접한 곳에 친구가 많을수록
		if (s.friends != friends) return s.friends > friends;
		//2. 같다면 비어있는 칸이 많을수록
		if (s.empty != empty) return s.empty > empty;
		//3. 같다면 행의 번호가 가장 작은 곳
		if (s.x != x) return s.x < x;
		//4. 같다면 열의 번호가 가장 작은 곳
		return s.y < y;
	}
};

struct student {
	int idx;
	int friends[4];
	pi seat;
};

bool isReachable(int x, int y) {
	if (x < 0 || x >= n || y < 0 || y >= n) return false;
	return true;
}

int main() {

	cin >> n;
	int stdnum = n * n;
	vector<student> students(stdnum);
	for (int i = 0; i < stdnum; i++) {
		cin >> students[i].idx;
		for (int j = 0; j < 4; j++) {
			cin >> students[i].friends[j];
		}
	}

	//자리 배치도
	vector<vector<int>> classroom(n, vector<int>(n));

	//1. 자리 배치하기
	for (int k = 0; k < stdnum; k++) {
		priority_queue<seat_info> pq;
		for (int i=0; i< n; i++) {
			for (int j = 0; j < n; j++) {
				//이미 (i, j)에 누가 앉아있을 경우 
				if (classroom[i][j] != 0) continue;
				//비어있는 자리의 수와 친구의 수
				int empty = 0;
				int friend_num = 0;

				for (int d = 0; d < 4; d++) {
					//(i, j)로부터 양옆위아래 체크
					int nextX = i + dx[d];
					int nextY = j + dy[d];
					if (!isReachable(nextX, nextY)) continue;
					if (classroom[nextX][nextY] == 0) {
						empty++;
						continue;
					}
					for (int s = 0; s < 4; s++) {
						if (classroom[nextX][nextY] == students[k].friends[s]) friend_num++;
					}
				}

				pq.push({ i, j, empty, friend_num });
			}
		}
		if (!pq.empty()) {
			int x = pq.top().x;
			int y = pq.top().y;
			classroom[x][y] = students[k].idx;
			students[k].seat.first = x;
			students[k].seat.second = y;
		}
	}

	//2. 만족도 계산
	int answer = 0;

	for (int i = 0; i < stdnum; i++) {
		int x = students[i].seat.first;
		int y = students[i].seat.second;
		int cnt = 0;

		for (int j = 0; j < 4; j++) {
			int nextX = x + dx[j];
			int nextY = y + dy[j];

			if (!isReachable(nextX, nextY)) continue;

			for (int k = 0; k < 4; k++) {
				if (classroom[nextX][nextY] == students[i].friends[k]) {
					cnt++;
					break;
				}
			}
		}
		answer += pow(10, cnt-1);
	}
	cout << answer;
}
