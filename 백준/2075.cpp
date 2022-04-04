#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	priority_queue<int, vector<int>, greater<int>> pq;
	//첫줄은 pq에 집어넣음
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		pq.push(n);
	}
	int cnt = N * N - N;
	while (cnt--) {
		int n;
		cin >> n;
		pq.push(n);
		pq.pop();
	}
	cout << pq.top();
}
