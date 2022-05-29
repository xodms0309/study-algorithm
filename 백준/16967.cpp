#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int h, w, x, y;
	cin >> h >> w >> x >> y;
	vector<vector<int>>v(h + x, vector<int>(w + y));
	vector<vector<int>>answer(h, vector<int>(w));

	for (int i = 0; i < h + x; i++) {
		for (int j = 0; j < w + y; j++) {
			cin >> v[i][j];
		}
	}
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (v[i][j] == 0) continue;
			if (i >= x && j >=y)  {
				answer[i][j] = v[i][j] - answer[i - x][j - y];
			}
			else answer[i][j] = v[i][j];
		}
	}
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cout << answer[i][j] << " ";
		}
		cout << "\n";
	}
}


