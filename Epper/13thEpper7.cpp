/*
이퍼 13회 7번
배열을 회문으로 만드는 최소 수정 횟수 구하기
*/
#include <iostream>
using namespace std;
int solution(int* arr, int start, int end);
int main() {
	int num = 0;
	int arr[100];
	cin >> num; //원소 개수
	for (int i = 0; i < num; i++) {
		cin >> arr[i];
	}
	int start = 0, end = num-1;
	cout << solution(arr, start, end);
}
int cnt=0;
int solution(int* arr, int start, int end) {
	while (start <= end) {
		if (arr[start] == arr[end]) {
			start += 1;
			end -= 1;
		}
		else {
			cnt++;
			if (arr[start] < arr[end]) {
				arr[start + 1] = arr[start] + arr[start + 1];
				start += 1;
			}
			else {
				arr[end - 1] = arr[end] + arr[end - 1];
				end -= 1;
			}
		}
	}
	return cnt;
}
