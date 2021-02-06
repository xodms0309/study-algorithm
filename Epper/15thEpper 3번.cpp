/*
	이화 쇼핑에서는 노트북이 하루에 1개씩 판매됩니다. 현재 N개의 노트북을 가지고 있고, M일마다 1개씩 재입고 됩니다.
	노트북의 개수가 0개가 될때까지 며칠이 걸리는지 구하시오.
*/
#include <stdio.h>
int main() {
	int day = 0;
	int N; //N개의 노트북
	int M; //M일마다 재입고
	scanf("%d %d", &N, &M);
	while (true) {
		day++;
		N--;
		if (day%M == 0) N++;  //M일마다 1개씩 재입고
		if (N == 0) break;
	}
	printf("%d", day);
}