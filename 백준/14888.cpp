/*
N개의 수로 이루어진 수열 A1, A2, ..., AN이 주어진다. 또, 수와 수 사이에 끼워넣을 수 있는 N-1개의 연산자가 주어진다. 연산자는 덧셈(+), 뺄셈(-), 곱셈(×), 나눗셈(÷)으로만 이루어져 있다.
우리는 수와 수 사이에 연산자를 하나씩 넣어서, 수식을 하나 만들 수 있다. 이때, 주어진 수의 순서를 바꾸면 안 된다.
N개의 수와 N-1개의 연산자가 주어졌을 때, 만들 수 있는 식의 결과가 최대인 것과 최소인 것을 구하는 프로그램을 작성하시오.
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
		scanf_s("%d", &op[i]); //연산자 개수
	}
	dfs(1, A[0]);
	printf("%d\n", dfs_max);
	printf("%d", dfs_min);
}