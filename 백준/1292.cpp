#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int start, end;
	vector <int> numArray(1001);
	int total = 0;
	cin >> start >> end;
	int k = 1;
	for (int i = 1; i <=1000; i++) {
		for (int j = 1; j <= i; j++) {
            numArray[k] = i;
			if (k > 1000) break;
            k++;
		}
	}
	for (int i = start; i <= end; i++) {
		total += numArray[i];
	}
	cout << total;
}
