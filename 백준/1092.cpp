#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> crane(n);
	for (int i = 0; i < n; i++) {
		cin >> crane[i];
	}
	int m;
	cin >> m;
	vector<int> box(m);
	for (int i = 0; i < m; i++) {
		cin >> box[i];
	}
	sort(crane.begin(), crane.end(), greater<>());
	sort(box.begin(), box.end(), greater<>());

	if (box[0] > crane[0]) {
		cout << -1;
		return 0;
	}
	int cnt = 0;
	while (!box.empty()) {
		cnt++;
		for (int i = 0; i < crane.size(); i++) {
			for (int j = 0; j < box.size(); j++) {
				if (crane[i] >= box[j]) {
					box.erase(box.begin() + j);
					break;
				}
			}
		}
	}
	cout << cnt;
}

