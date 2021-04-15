/*
�ڿ��� N�� M�� �־����� ��, �Ʒ� ������ �����ϴ� ���̰� M�� ������ ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

1���� N���� �ڿ��� �߿��� �ߺ� ���� M���� �� ����
�� ������ ���������̾�� �Ѵ�.
*/
#include <iostream>
using namespace std;
int n, m;//n���� ����, �迭 ���̴� m
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