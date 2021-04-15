/*
�ڿ��� N�� M�� �־����� ��, �Ʒ� ������ �����ϴ� ���̰� M�� ������ ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

1���� N���� �ڿ��� �߿��� M���� �� ����
���� ���� ���� �� ��� �ȴ�.

Ǯ��) ���� ������ ���� �˰����ε� visited ���� üũ�� ���� ��
*/
#include <iostream>
using namespace std;
int n, m;//n���� ����, �迭 ���̴� m
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