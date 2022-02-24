#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;	

int main() {
	int T;
	cin >> T;
	while (T--) {
		int num;
		cin >> num;	
		vector<int> DP(10001);
		DP[0] = 1;
		for (int i = 1; i <= 3; i++) {
			for (int j = i; j <= num; j++) {
				DP[j] +=DP[j - i];
			}
		}
		cout << DP[num]<<"\n";
	}
}
