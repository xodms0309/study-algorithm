#include <iostream>
#include<algorithm>
#include <vector>

using namespace std;
int main() {
	int N, K;
	int answer = 0;
	cin >> N >> K;
	vector <int> products(K);
	vector <int> multitab;
	for (int i = 0; i < K; i++) {
		cin >> products[i];
	}

	for (int i = 0; i < K; i++) {
		auto iter = find(multitab.begin(), multitab.end(), products[i]);
		if (iter != multitab.end()) continue;
		else {
			if (multitab.size() < N) {
				multitab.push_back(products[i]);
			}
			else {
				int idx = 0, productIdx = 0;
				for (int j = 0; j < N; j++) {
					int lastIdx = 0;
					for (int k = i + 1; k < K; k++) {
						if (multitab[j] == products[k]) break;
						lastIdx++;
					}
					if (lastIdx > productIdx) {
						idx = j;
						productIdx = lastIdx;
					}
				}
				answer++;
				multitab[idx] = products[i];
			}
		}
		
	}
	cout << answer;

}
