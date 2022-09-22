#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
typedef pair<char, int> ci;	
map<char, int> m;
int convertToNum(string s) {
	char previous = s[0];
	int answer = m[previous];
	for (int i = 1; i < s.length(); i++) {
		char current = s[i];
		//
		if (m[previous] < m[current]) {
			answer += m[current] - m[previous] * 2;
		}
		else {
			answer += m[current];
		}
		previous = current;
	}
	return answer;
}

string convertToRoma(int num) {
	string answer;
	int thousand = num / 1000;
	num %= 1000;
	while (thousand--) answer += 'M';
	int hundred = num / 100;
	num %= 100;
	if (hundred == 4 || hundred == 9) {
		answer += 'C';
		if (hundred == 4) answer += 'D';
		else answer += 'M';
	}
	else {
		if (hundred >= 5) {
			answer += 'D';
			hundred -= 5;
		}
		while (hundred--) {
			answer += 'C';
		}
	}
	int ten = num / 10;
	num %= 10;
	if (ten == 4 || ten == 9) {
		answer += 'X';
		if (ten == 4) answer += 'L';
		else answer += 'C';
	}
	else {
		if (ten >= 5) {
			answer += 'L';
			ten -= 5;
		}
		while (ten--) {
			answer += 'X';
		}
	}

	int one = num;
	if (one == 4 || one == 9) {
		answer += 'I';
		if (one == 4) answer += 'V';
		else answer += 'X';
	}
	else {
		if (one >= 5) {
			answer += 'V';
			one -= 5;
		}
		while (one--) {
			answer += 'I';
		}
	}
	return answer;
}
int main() {

	m.insert({ 'I', 1 });
	m.insert({ 'V', 5 });
	m.insert({ 'X', 10 });
	m.insert({ 'L', 50 });
	m.insert({ 'C', 100 });
	m.insert({ 'D', 500 });
	m.insert({ 'M', 1000 });

	string s1;
	string s2;
	cin >> s1 >> s2;
	cout << convertToNum(s1)+convertToNum(s2) << "\n";
	cout << convertToRoma(convertToNum(s1) + convertToNum(s2));
}
