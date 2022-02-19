#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	//S의 범위가 int를 넘어가기 때문에 long long으로 선언해줘야 함
	long long S;
	cin >> S;
	int N;
	long long sum = 0;
	int i = 1;
	int answer = 0;
	while (true) {
		sum += i;
		if (sum > S) break;
		if (S - sum > i) {
			answer = max(answer, i);
		}
		i++;
	}
	cout << answer+1;
}
