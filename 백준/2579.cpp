#include <iostream>
#define MAX 301
using namespace std;
int main() {
	int n;
	int stairs[MAX];
	int DP[MAX];
	int result = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> stairs[i];
	}
	//DP[i]���� i��° ����� �������� ���
	DP[0] = stairs[0];
	DP[1] = stairs[0] + stairs[1];
	DP[2] = max(stairs[1] + stairs[2], stairs[0] + stairs[2]);
	for (int i = 3; i < n; i++) {
		DP[i] = max(stairs[i] + DP[i - 2], stairs[i] + stairs[i - 1] + DP[i - 3]);
		//ù ��° ���� i��° ����� �����ϰ� i-1��° ��� ���� x
		//�� ��° ���� i��° ����� �����ϰ� i-1��° ��� ���� o
	}
	cout << DP[n-1];
}