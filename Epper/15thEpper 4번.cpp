/*
	입력되는 9개의 숫자 중 7개의 숫자 합이 100이 되도록 하시오.
*/
#include <stdio.h>
int main() {
	int arr[9];
	int sum = 0;
	for (int i = 0; i < 9; i++) {
		scanf("%d", &arr[i]);
		sum += arr[i];
	}

	for (int i = 0; i < 9; i++) {
		for (int j = i + 1; j < 9; j++) {
			if (sum - arr[i] - arr[j] == 100) {
				arr[i] = -1;
				arr[j] = -1;
			}
		}
	}
	for (int i = 0; i < 9; i++) {
		if (arr[i] > 0) printf("%d ", arr[i]);
	}
	
}