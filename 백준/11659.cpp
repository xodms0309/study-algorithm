#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	vector<int> numbers(n+1);
	vector<int> sum(n + 1, 0);

	for (int i = 1; i <= n; i++) {
		cin >> numbers[i];
		sum[i] = sum[i]+ sum[i-1]+numbers[i];
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		cout << sum[b] - sum[a-1] << "\n";
	}

}
