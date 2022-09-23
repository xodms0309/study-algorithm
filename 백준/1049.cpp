#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef pair<int, int> pi;

bool cmp(pi& a, pi& b) {
	return a.second < b.second;
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<pi> brand;
	int answer = 0;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		brand.push_back({ a, b });
	}
	//만약 필요한 줄이 6개 이상이라면 6개 묶음으로 정렬
	sort(brand.begin(), brand.end());
	int six = brand[0].first;
	int q = n / 6;
	int r = n % 6;
	sort(brand.begin(), brand.end(), cmp);
	int one = brand[0].second;
	//다 세트로 살 때 or 세트+단품으로 살 때 or 다 단품으로 살 때
	answer = min((q + 1) * six, min(q * six + r * one, n * one));
	cout << answer;

}

