#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	int n;	
	cin >> n;
	vector<int> card(n);
	priority_queue<int, vector<int>, greater<>>pq;
		for (int i = 0; i < n; i++) {
		cin >> card[i];
		pq.push(card[i]);
	}
	int answer = 0;
	while (pq.size()>1) {	
		int current = pq.top();
		pq.pop();
		int next = pq.top();
		pq.pop();
		answer = answer + current + next;
		pq.push(current+next);
	}
	cout <<answer;
}
