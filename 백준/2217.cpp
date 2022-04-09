#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int N;
	cin >> N;
	vector<long long>w(N);
	for (int i = 0; i < N; i++) {
		cin >> w[i];
	}
	sort(w.begin(), w.end(), greater<int>());
	long long answer = 0;
	for (int i = 0; i < N; i++) {
		answer = max(answer, w[i] * (i + 1));
	}
	cout << answer;
	
}	
