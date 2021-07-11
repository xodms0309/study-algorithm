#include <iostream>
#include <string>
#include <queue>
using namespace std;
int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);
	int n;
	int num = 0;
	cin >> n; //명령 개수
	queue <int> q;
	string s;
	for (int i = 0; i < n; i++) {
		cin >>s; //명령
		if (s == "push") {
			cin >> num;
			q.push(num);
		}
		else if (s == "pop") {
			if (q.size() == 0) printf("-1\n");
			else {
				printf("%d\n", q.front());
				q.pop();
			}
		}
		else if (s == "front") {
			if (q.size() == 0)  printf("-1\n");
			else printf("%d\n", q.front());
		}
		else if (s == "back") {
			if (q.size() == 0)  printf("-1\n");
			else printf("%d\n", q.back());
		}
		else if (s == "size") {
			printf("%d\n", q.size());
		}
		else if (s == "empty") {
			printf("%d\n", q.empty());
		}
	}
}
