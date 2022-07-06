#include <iostream>
#include <vector>
#include <string>
#include<deque>
#include <algorithm>
using namespace std;

string AC(string p, deque<int> & arr) {
	int reverse_cnt=0;
	//매번 reverse를 해준다면 시간 초과가 난다
	for (int i = 0; i < p.length(); i++) {
		if (p[i] == 'R') {
			reverse_cnt++;
		}
		else {
			if (arr.empty()) return "error";
			if (reverse_cnt % 2 == 0) arr.pop_front();
			else arr.pop_back();
		}
	}

	if (reverse_cnt % 2 != 0) reverse(arr.begin(), arr.end());
	
	string res = "[";
	for (int i = 0; i < arr.size(); i++) {
		res += to_string(arr[i]);
		if (i != arr.size() - 1) res += ",";
	}
	res += "]";
	return res;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		string p; //수행할 함수
		cin >> p;
		int n;
		cin >> n;
		deque<int> arr;
		string temp; //배열
		cin >> temp; 
		string str=""; //두 자리 수가 들어올 것을 대비

		//string->int형 배열로 바꾸는 과정
		for (int i = 0; i < temp.length(); i++) {
			if (temp[i] == '[') continue;
			if (temp[i] == ',' || temp[i] == ']') {
				if (str.length()==0) continue;
				arr.push_back(stoi(str));
				str = "";
				continue;
			}
			str += temp[i];
		}
		cout << AC(p, arr) << "\n";
	}
}
