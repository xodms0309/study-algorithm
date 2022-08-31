#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, h;
int answer=4;
vector<vector<int>> ladder(12, vector<int>(32, 0));

bool check() {
	for (int i = 1; i <= n; i++) {
		int current = i;
		for (int j = 1; j <= h; j++) {
			if (ladder[current][j]) current+=1;
			else if (ladder[current - 1][j]) current-=1;
		}
		if (current != i) return false;
	}
	return true;
}

void dfs(int y, int depth) {	
	if (depth >= 4) {
		return;
	}
	if (check()) {
		answer = min(answer, depth);
		return;
	}
	for (int i = y; i <= h; i++) {
		for (int j = 1; j < n; j++) {
			//사다리 연결할 수 있는 지
			if (ladder[j][i] || ladder[j-1][i] || ladder[j+1][i]) continue;
			ladder[j][i] = 1;
			dfs(i, depth + 1);
			ladder[j][i] = 0;
		}
	}

}

int main() {
	cin >> n >> m >> h;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		ladder[b][a] = 1;
	}

	dfs(1, 0);

	if (answer >= 4) cout << -1;
	else cout << answer;
}

