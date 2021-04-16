/*
N-Queen ������ ũ�Ⱑ N �� N�� ü���� ���� �� N���� ���� ������ �� ���� ���� �����̴�.
N�� �־����� ��, ���� ���� ����� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
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
		if ((col[row]== col[k]) || (abs(col[row] - col[k]) == row - k)) return false; //���� �࿡ ��ġ�ϰų� �밢���� ��ġ�� ��
		else k++;
	}
	return true;
}
void nqueen(int row) {
	if (row>n) {
		cnt++; //row==n�̶�� ������ �ɸ� ���� ������ üũ���� �ʱ� ������ n���� Ŭ�� Ȥ�� n+1�� �������� ������ üũ�ؾ� ��
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