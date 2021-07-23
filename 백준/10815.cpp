#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> card;
int binarySearch(int low, int high,int key) {
	while (low <= high) {
		int mid = (low + high) / 2;
		if (card[mid] == key) return 1;
		else if (key < card[mid]) {
			high = mid - 1;
		}
		else low = mid + 1;
	}
	return 0;
}
int main() {
	int N, M;
	cin >> N;
	card.resize(N);
	for (int i = 0; i < N; i++) {
		scanf_s("%d", &card[i]);
	}
	sort(card.begin(), card.end());
	cin >> M;
	vector <int> guess(M);
	for (int i = 0; i < M; i++) {
		scanf_s("%d", &guess[i]);
		cout<<binarySearch(0, N-1, guess[i])<<"\n";
	}
}
