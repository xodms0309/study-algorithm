#include <iostream>
#include <vector>
using namespace std;
int answer = -1e9;

int calculate(int x, int y, char op) {
	switch (op) {
	case '+': x += y; break;
	case '-': return x -= y; break;
	case '*': return x *= y; break;
	}
	return x;
}

void recursive(string str, int n, int idx, int result) {
	if (idx >= n) {
		answer = max(answer, result);
		return;
	}
	
	char op='+';
	if (idx>0) op = str[idx-1];
	//괄호 쳤을 때
	if (idx + 2 < n) {
		int temp = calculate(str[idx]-'0', str[idx + 2]-'0', str[idx+1]);
		recursive(str, n, idx + 4, calculate(result, temp, op));
	}

	//괄호 안 쳤을 때
	recursive(str, n, idx + 2, calculate(result, str[idx] - '0', op));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	string str;
	cin >> str;
	recursive(str, n, 0, 0);
	cout << answer;
}
