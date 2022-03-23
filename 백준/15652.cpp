#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;	
int N, M;
vector<bool>visited;
vector<int>num;
void dfs(int n, int depth) {
	if (depth == M) {
		for (int i = 0; i < M; i++) {
			cout << num[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = n; i <= N; i++) {
		num[depth] =i;
		dfs(i,depth + 1);
	}
}
int main() {
	cin >> N >> M;
	//N개 자연수 중 M개 고름
	visited.assign(N+1, false);
	num.assign(N+1,0);
	dfs(1, 0);
}
