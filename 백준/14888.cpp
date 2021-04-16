/*
N���� ���� �̷���� ���� A1, A2, ..., AN�� �־�����. ��, ���� �� ���̿� �������� �� �ִ� N-1���� �����ڰ� �־�����. �����ڴ� ����(+), ����(-), ����(��), ������(��)���θ� �̷���� �ִ�.
�츮�� ���� �� ���̿� �����ڸ� �ϳ��� �־, ������ �ϳ� ���� �� �ִ�. �̶�, �־��� ���� ������ �ٲٸ� �� �ȴ�.
N���� ���� N-1���� �����ڰ� �־����� ��, ���� �� �ִ� ���� ����� �ִ��� �Ͱ� �ּ��� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
\*/
#include <iostream>
using namespace std;
#define MAX 11
int n;
int dfs_max = -1000000000;
int dfs_min = 1000000000;
int op[4];
int A[MAX];
void dfs(int depth, int result) {
	if (depth == n) {
		if (result >= dfs_max) dfs_max = result;
		if (result <= dfs_min) dfs_min = result;
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (op[i] > 0) {
			op[i]--;
			switch (i) {
			case 0:
				dfs(depth + 1, result+A[depth]);
				op[i]++;
				break;
			case 1:
				dfs(depth + 1,result-A[depth]);
				op[i]++;
				break;
			case 2:
				dfs(depth + 1, result*A[depth]);
				op[i]++;
				break;
			case 3:
				dfs(depth + 1, result/A[depth]);
				op[i]++;
				break;
			}
		}
	}
	return;
}
int main() {
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &A[i]);
	}
	for (int i = 0; i < 4; i++) {
		scanf_s("%d", &op[i]); //������ ����
	}
	dfs(1, A[0]);
	printf("%d\n", dfs_max);
	printf("%d", dfs_min);
}