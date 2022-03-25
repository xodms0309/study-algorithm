#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> root(1000001);
int find(int node) {
	if (root[node] == node) return node;
	else return root[node] = find(root[node]);
}
void unionNum(int a, int b) {
	int parent_a = find(a);
	int parent_b = find(b);
	if (a > b) root[parent_a] = parent_b;
	else root[parent_b] = parent_a;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, M;
	cin >> N >> M;
	for (int i = 0; i <= N; i++) {
		root[i] = i;
	}
	for (int i = 0; i < M; i++) {
		int op, a, b;
		cin >> op >> a >> b;
		if (op == 0) {
			unionNum(a,b);
		}
		else {
			if (find(a) == find(b)) cout << "YES\n";
			else cout << "NO\n";
		}
	}
}
