#include <iostream>
#include <vector>
using namespace std;
int main() {
	int n;
	cin >> n;
	//목표 수열
	vector <int> seq(n);
	vector <int> stack;
	vector <char> answer;
	int j = 0;
	for (int i = 0; i < n; i++) {
		cin >> seq[i];
	}
	for (int i =1; i <= n; i++) {
		stack.push_back(i);
		answer.push_back('+');

		while (!stack.empty() && stack.back() == seq[j]) {
			stack.pop_back();
			answer.push_back('-');
			j++;
		}
	}
	if (!stack.empty()) cout << "NO";
	else {
		for (int i = 0; i < answer.size(); i++) {
			cout << answer[i] << "\n";
		}
	}
}
