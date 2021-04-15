/*
자연수 N과 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.

1부터 N까지 자연수 중에서 M개를 고른 수열
같은 수를 여러 번 골라도 된다.

풀이) 이전 문제와 같은 알고리즘인데 visited 조건 체크만 빼면 됨
*/
#include <iostream>
using namespace std;
int n, m;//n까지 숫자, 배열 길이는 m
int depth;
int arr[8] = { 0, };
bool visited[8] = { false, };
void dfs(int depth) {
	if (depth == m) {
		for (int i = 0; i < m; i++) {
			printf("%d ", arr[i]);
		}
		printf("\n");
		return;
	}
	for (int i = 0; i < n; i++) {
		visited[i] = true;
		arr[depth] = i+1;
		dfs(depth + 1);
		visited[i] = false;
	}
}
int main() {
	scanf_s("%d %d", &n, &m);
	dfs(0);
}