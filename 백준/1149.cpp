#include <iostream>
#define MAX 1001
using namespace std;
int main() {
	int n;
	cin >> n;
	int DP[3];
	int cost[MAX][3] = { 0 };
	for (int i = 1; i <= n; i++) {
		cin >> DP[0] >> DP[1] >> DP[2]; //순서대로 R, G, B
		cost[i][0] += DP[0] + min(cost[i-1][1], cost[i-1][2]);
		cost[i][1] += DP[1] + min(cost[i-1][0], cost[i-1][2]);
		cost[i][2] += DP[2] + min(cost[i-1][0], cost[i-1][1]);
	}
	cout << min(cost[n][0], min(cost[n][1], cost[n][2]));
}