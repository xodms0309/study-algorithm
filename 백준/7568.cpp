#include <iostream>
#include <vector>
using namespace std;	

int main() {
	int N;
	cin >> N;
	vector<vector<int>> people(N + 1, vector<int>(N + 1));
	for (int i = 0; i < N; i++) {
		cin >> people[i][0] >> people[i][1];
	}
	for (int i = 0; i < N; i++) {
		int rank = 1;
		for (int j = 0; j < N; j++) {
			if (people[i][0] < people[j][0] && people[i][1] < people[j][1]) {
				rank++;
			}
		}
		cout << rank << " ";
	}
}
