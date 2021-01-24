//N개의 수가 주어졌을 때, 이를 오름차순으로 정렬하는 프로그램을 작성하시오. (삽입정렬 사용)
#include <stdio.h>
#define MAX 1000
int main() {
	int list[MAX];
	int n=0; //
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &list[i]);
	}
	int key; int j;
	for (int i = 1; i < n; i++) {
		key = list[i];
		for (j = i - 1; j >= 0 && list[j] > key; j--) {
			list[j + 1] = list[j];
		}
		list[j + 1] = key;
	}
	for (int i = 0; i < n; i++) {
		printf("%d\n", list[i]);
	}
}