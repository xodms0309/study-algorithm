#include <iostream>
#include <algorithm>
#include <vector>	
using namespace std;
int N;
int maxRow = 0, maxCol = 0;
int maxCandy = 0;
vector<vector<char>> candy(50, vector<char>(50));

void explore() {
	for (int i = 0; i < N; i++) {
		int rowCnt = 1;
		int colCnt = 1;
		for (int j = 0; j < N; j++) {
			if (candy[i][j] == candy[i][j + 1]) rowCnt++;
			else {
				maxRow = max(maxRow, rowCnt);
				rowCnt = 1;
			}
			if (candy[j][i] == candy[j+1][i])  colCnt++;
			else {
				maxCol = max(maxCol, colCnt);
				colCnt = 1;
			}
		}
	}
	maxCandy = max(maxRow, maxCol);
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> candy[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (candy[i][j + 1]) {
				swap(candy[i][j], candy[i][j + 1]);
				explore();
				swap(candy[i][j], candy[i][j + 1]);
			}
			if (candy[i+1][j]) {
				swap(candy[i][j], candy[i+1][j]);
				explore();
				swap(candy[i][j], candy[i+1][j]);
			}
		}
	}

	cout << maxCandy;

}
