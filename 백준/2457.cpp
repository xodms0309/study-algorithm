#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pi;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector<pi> flowers;
	for (int i = 0; i < n; i++) {
		int s1, s2, e1, e2;
		cin >> s1 >> s2 >> e1 >> e2;
		flowers.push_back({ 100 * s1 + s2, 100 * e1 + e2 });
	}
	sort(flowers.begin(), flowers.end());
	int day = 301;
	int cnt = 0;
	int idx = 0;
	while (day <= 1130) {	
		int max_time = 0;
		for (int i = idx; i < n; i++) {
			if (flowers[i].first > day) break;
			//더 늦게 지는 꽃을 선택해야 함
			max_time = max(max_time, flowers[i].second);
			idx = i+1;
		}
		//더 선택할 꽃이 없음
		if (max_time == 0) break;
		day = max_time;
		cnt++;
	}
	if (day > 1130) cout << cnt;
	else cout << 0;

}
