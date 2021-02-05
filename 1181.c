//알파벳 소문자로 이루어진 N개의 단어가 들어오면 아래와 같은 조건에 따라 정렬하는 프로그램을 작성하시오.
//
//길이가 짧은 것부터
//길이가 같으면 사전 순으로
/*풀이 방법: merge sort
quick sort를 썼더니 최악의 경우를 계산하게 되는지 시간초과 에러가 떠서 merge sort를 사용했다.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
	char str[51];
	int length;
}word;
void merge(word *list, int left, int mid, int right);
void merge_sort(word *list, int left, int right);

int main() {
	int n; //N개의 단어
	scanf("%d", &n);
	word arr[n];

	for (int i = 0; i < n; i++) {
		scanf("%s", arr[i].str);
		arr[i].length = strlen(arr[i].str);
	}
	merge_sort(arr, 0, n - 1);

	printf("%s\n", arr[0].str);
	for (int i = 1; i < n; i++) {
		if (strcmp(arr[i - 1].str, arr[i].str) != 0) //단어가 중복되는 경우
			printf("%s\n", arr[i].str);
	}
}

void merge(word *list, int left, int mid, int right) {
	int i, j, k;
	i = left;
	j = mid + 1;
	k = left;
	word sorted[20001];

	//분할 정렬된 list의 합병
	while (i <= mid && j <= right) {
		if (list[i].length < list[j].length)
			sorted[k++] = list[i++];
		else if (list[i].length>list[j].length)
			sorted[k++] = list[j++];
		else { //길이가 같을 때
			if (strcmp(list[i].str, list[j].str) < 0) {  //strcmp값이 <0이면 str1<str2
				sorted[k++] = list[i++];
			}
			else {
				sorted[k++] = list[j++];
			}
		}
	}
	//남아있는 레코드의 일괄 복사
	if (i <= mid) {
		while (i <= mid) {
			sorted[k++] = list[i++];
		}
	}
	else {
		while (j <= right) {
			sorted[k++] = list[j++];
		}
	}

	for (k = left; k <= right; k++) {
		list[k] = sorted[k];
	}

}
void merge_sort(word *list, int left, int right) {
	int mid;
	if (left < right) {
		mid = (left + right) / 2;
		merge_sort(list, left, mid); //부분리스트 정렬
		merge_sort(list, mid + 1, right); //부분리스트 정렬
		merge(list, left, mid, right);//합병
	}
}
