#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;	

int main() {
	int N, S, M; //곡의 개수, 시작 볼륨, 최대볼륨
	cin >> N >> S >> M;
	vector <int> V(51);
	for (int i = 1; i <= N; i++) {
		cin >> V[i];
	}
	int P = S;
	int answer = -1;
	vector<vector<bool>>DP(51, vector<bool>(1002));
	DP[0][S] = true;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= M; j++) {
			if (DP[i][j]) {
				if (j + V[i+1] <= M) 
					DP[i+1][j+ V[i+1]] = true;
				if (j- V[i+1] >= 0)
					DP[i+1][j- V[i+1]] = true;
			}

		}
	}

	for (int i = M; i >= 0; i--) {
		if (DP[N][i]) {
			answer = i;
			break;
		}
	}
	cout << answer;
}
