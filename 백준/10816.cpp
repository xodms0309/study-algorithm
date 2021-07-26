#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int N;
	cin >> N;
	vector <int> card(N);
	for (int i = 0; i < N; i++) {
		scanf_s("%d", &card[i]);
	}
	sort(card.begin(), card.end());
	int M;
	cin >> M;
	vector <int> guess(M);
	for (int i = 0; i < M; i++) {
		scanf_s("%d", &guess[i]);
		cout << upper_bound(card.begin(), card.end(), guess[i]) - lower_bound(card.begin(), card.end(), guess[i]);
		cout << " ";
	}
}
