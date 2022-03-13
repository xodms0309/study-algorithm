#include <iostream>
#include <vector>
using namespace std;	
int main() {
	int N, P;
	cin >> N >> P;
	vector<vector<int>> v(7, vector<int>(P));
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		int line, fret;
		cin >> line >> fret;
		if (v[line].empty()) {
			//비어있으면 그냥 스택에 넣기
			v[line].push_back(fret);
			cnt++;
		}
		else {
			if (v[line].back() < fret) {
				v[line].push_back(fret);
				cnt++;
			}
			else if (v[line].back() == fret) {
				continue;
			}
			else {
				while (v[line].back() > fret) {
					v[line].pop_back();
					cnt++;
				}
				if (v[line].back() == fret) continue;
				else {
					v[line].push_back(fret);
					cnt++;
				}
			}
		}
	}
	cout << cnt;
}

