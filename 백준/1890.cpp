#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;	

int main() {
	int N;
	cin >> N;
	vector <vector<int>>graph(N, vector<int>(N));
	vector <vector<long long>>DP(N, vector<long long>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> graph[i][j];
		}
	}
	DP[0][0] = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (DP[i][j] == 0) continue;
			if (graph[i][j]==0) break;
			else { 
				int right = graph[i][j] + j;
				int down = graph[i][j] + i;
				if (down < N) DP[down][j] += DP[i][j];
				if (right < N) DP[i][right] += DP[i][j];
			}
		}
	}
	cout << DP[N - 1][N - 1];

}
