#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main() {
	int N;
	cin >> N;
	queue <int> card;
	for (int i = 1; i <= N; i++) {
		card.push(i);
	}
	while (true) {
		if (card.size() == 1) break;
		//가장 위 카드 버림
		card.pop();
		int front = card.front();
		card.pop();
		card.push(front);
	}
	cout << card.front();
}

