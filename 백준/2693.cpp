#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int T;
	cin >> T;
	while (T--) {	
		vector <int> numArray(10);
		for (int i = 0; i < 10; i++) {
			cin >> numArray[i];
		}
		sort(numArray.begin(), numArray.end());
		cout << numArray[7] << "\n";
	}
}
