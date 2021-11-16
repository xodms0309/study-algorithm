#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;
  //처음 알게된 라이브러리..
	priority_queue<int, vector<int>, greater<int>> pq;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		if (x == 0 && pq.empty()) {
			cout << "0" << "\n";
		}
		else if (x == 0 && !pq.empty()) {
			cout << pq.top() << "\n";
			pq.pop();
		}
		else pq.push(x);
	}
	return 0;
}
