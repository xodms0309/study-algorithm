#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>	
using namespace std;

int main() {
	int N;
	cin >> N;
	int id = 10;
	queue<long long> q;
	vector <long long> arr(1000001);
	for (int i = 0; i <= 9; i++) {
		q.push(i);
		arr[i] = i;
	}
	while (id <= N && !q.empty()) {
		long long num = q.front();
		q.pop();
		int last = num % 10;
		for (int i = 0; i < last; i++) {
			q.push(num * 10 + i);
			arr[id] = num * 10 + i;
			id++;
		}
	}
	if (id >= N && arr[N] != 0) cout << arr[N];
	else if (N == 0) cout << 0;
	else cout << -1;
}
