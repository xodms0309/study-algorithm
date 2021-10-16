#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int A, B;
vector <int>visited(10001);
void bfs() {
	int D, S, L, R = 0;
	queue<pair<int, string>> q; //현재 숫자, 현재 연산
	//visited[A] = true;
	q.push(make_pair(A, ""));
	while (!q.empty()) {
		int currentNum = q.front().first;
		string currentOp = q.front().second;
		q.pop();
		if (currentNum == B) {
			cout << currentOp <<"\n";
			break;
		}
		//D연산
		D = (2 * currentNum) % 10000;
		if (!visited[D]) {
			visited[D] = true;
			q.push(make_pair(D, currentOp+"D"));
		}
		//S연산
		S = (currentNum - 1) >= 0 ? currentNum - 1 : 9999; //여기서 = 안넣어서 30분동안 찾음 ..
		if (!visited[S]) {
			visited[S] = true;
			q.push(make_pair(S, currentOp + "S"));
		}
		//L연산
		L = (currentNum % 1000) * 10 + (currentNum / 1000);
		if (!visited[L]) {
			visited[L] = true;
			q.push(make_pair(L, currentOp + "L"));
		}
		//R연산
		R = (currentNum % 10)*1000 + (currentNum / 10);
		if (!visited[R]) {
			visited[R] = true;
			q.push(make_pair(R, currentOp + "R"));
		}
	}
	
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		visited.assign(10001, false);
		cin >> A >> B;
		visited[A] = true;
		bfs();
	}
}
