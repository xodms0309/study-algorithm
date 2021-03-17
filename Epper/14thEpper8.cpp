#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int solution(int N, int M, vector<vector<int>> arr);
int main() {
	int N, M;
	cin >> N;
	cin >> M;
	vector<vector<int>>arr(M, vector<int>(N, 0)); //2���� �迭 ����
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}
	cout << solution(N, M, arr);
}
	
int solution(int N,int M, vector<vector<int>> arr) {
	int cnt = 0;
	queue<pair<int,int>> q;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] == 0) cnt++; //���� ������ �丶�� ��
			if (arr[i][j] == 1) q.push(make_pair(i,j)); //���� �丶��� ť�� ����
		}
	}
	int vectX[4] = { -1,1,0,0 };
	int vectY[4] = { 0,0,1,-1 }; //��ǥ �̵��� ����
	int x=0, y=0;
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nextX = x + vectX[i];
			int nextY = y + vectY[i];
			if ((nextX >= 0 && nextX < M) && (nextY >= 0 && nextY < N)) {
				if (arr[nextX][nextY] == 0) {
					cnt--;
					arr[nextX][nextY] = arr[x][y] + 1;
					q.push(make_pair(nextX, nextY));
				}
			}
		}
	}
	if (cnt == 0) return arr[x][y] - 1;
	else return -1;
}