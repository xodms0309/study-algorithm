#include <iostream>
#define MAX 501
using namespace std;
int best[MAX][MAX];
int arr[MAX][MAX];
int max_result = 0;

int number_triangle(int n, int arr[MAX][MAX]) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			best[i][j] = arr[i][j] + max(best[i - 1][j - 1], best[i - 1][j]);
		}
	}
	for (int i = 1; i <= n; i++) {
		if (max_result < best[n][i]) max_result = best[n][i];
	}
	return max_result;
}
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin>> arr[i][j];
		}
	}
	cout << number_triangle(n, arr);

}