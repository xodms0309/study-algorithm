/*
N-Queen 문제는 크기가 N × N인 체스판 위에 퀸 N개를 서로 공격할 수 없게 놓는 문제이다.
N이 주어졌을 때, 퀸을 놓는 방법의 수를 구하는 프로그램을 작성하시오.
*/
#include <iostream>
using namespace std;
#define MAX 15
int n;
int col[MAX];
int cnt = 0;
bool isPromising(int row) {
	int k = 1;
	while (k < row) {
		if ((col[row]== col[k]) || (abs(col[row] - col[k]) == row - k)) return false; //같은 행에 위치하거나 대각선에 위치할 때
		else k++;
	}
	return true;
}
void nqueen(int row) {
	if (row>n) {
		cnt++; //row==n이라는 조건을 걸면 밑의 조건을 체크하지 않기 때문에 n보다 클때 혹은 n+1과 같을때로 조건을 체크해야 됨
	}
	else {
		for (int i = 1; i <= n; i++) {
			col[row] = i;
			if (isPromising(row)) nqueen(row + 1);
		}
	}
}
int main() {
	scanf_s("%d", &n);
	nqueen(1);
	printf("%d", cnt);
}