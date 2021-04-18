#include <iostream>
using namespace std;
#define MAX 20
int n;
int S[MAX][MAX];
bool visited[MAX] = { false, };
int index = 0l;
int soccer_min=1000000000;
int result;
void dfs(int index, int depth) {
	if (depth == n / 2) {
		int start = 0;
		int link = 0;
		for (int i = 0; i < n; i++) {
			for (int j = i+1; j < n; j++) {
				if (visited[i] && visited[j]) {
					start = start + S[i][j]+S[j][i];
				}
				else if (!(visited[i]|| visited[j])) {
					link = link + S[i][j]+S[j][i];
				}
			}
		}
		result = abs(start - link);
		soccer_min = min(result, soccer_min);
	}
	for (int i = index; i < n; i++) {
		if (!visited[i]) {
			visited[i] = true;
			dfs(i, depth + 1); 
			visited[i] = false;
		}
	}
	
}
int main() {
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf_s("%d", &S[i][j]);
		}
	}
	dfs(0,0);
	printf("%d", soccer_min);

}