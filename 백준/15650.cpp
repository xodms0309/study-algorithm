/*
자연수 N과 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.

1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열
고른 수열은 오름차순이어야 한다.
*/
#include <iostream>
using namespace std;
int n, m;//n까지 숫자, 배열 길이는 m
int depth;
int arr[8] = { 0, };
bool visited[8] = { false, };
int index;
void dfs(int depth, int index) {
	if (depth == m) {
		for (int i = 0; i < m; i++) {
			printf("%d ", arr[i]);
		}
		printf("\n");
	}
	for (int i = index; i < n; i++) {
		if (!visited[i]) {
			visited[i] = true;
			arr[depth] = i+1;
			dfs(depth + 1, i+1);
			visited[i] = false;
		}
	}

}
int main() {
	scanf_s("%d %d", &n, &m);
	dfs(0, 0);
}