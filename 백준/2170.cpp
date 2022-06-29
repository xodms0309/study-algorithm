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
	vector<pi> dots;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		dots.push_back({ x, y });
	}
	sort(dots.begin(), dots.end());
	pi lines;
	int cnt = 0;
	lines={ dots[0].first, dots[0].second };
	int idx = 0;
	for (int i = 1; i < n; i++) {
		//선이 겹치는 경우
		if (dots[i].first < lines.second) {
			lines.second = max(lines.second, dots[i].second);
		}
		//선이 겹치지 않는다면 앞 선에 더 이상 추가되는 경우가 없으므로 길이를 더해주고 현재 직선을 바꿔줌
		else {
			cnt += (lines.second - lines.first);
			lines = { dots[i].first, dots[i].second };
		}
	}
	cnt += lines.second - lines.first;
	cout << cnt;

}
