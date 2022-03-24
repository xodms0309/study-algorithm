#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;	
vector<int> v;	
int answer = 0;
bool check(int N, int C, int mid) {
	int cnt = 1;
	int prev = v.front();
	for (int i = 1; i < N; i++) {
		if (v[i] - prev >= mid) {
			cnt++;
			prev = v[i];
		}
	}
	if (cnt >= C) return true;
	else return false;
}
void binarySearch(int N, int C) {
	//거리의 최소, 최대값
	int start = 1;
	int end =v.back()-v.front();
	while (start <= end) {
		int mid = (start + end) / 2;
		if (check(N, C, mid)) {
			//C개 설치 가능하다면 최소 거리 증가
			answer = max(answer, mid);
			start = mid + 1;
		}
		else end = mid - 1;
	}
}
int main() {
	int N, C;
	cin >> N >> C;
	v.assign(N, 0);
	vector <int> house(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	binarySearch(N, C);
	cout << answer;
}

