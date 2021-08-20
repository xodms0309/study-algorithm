#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector <int> height(9);
	int sum = 0;
	bool find = false;
	for (int i = 0; i < 9; i++) {
		cin >> height[i];
		sum += height[i];
	}
	for (int i = 0; i < 8; i++) {
		for (int j = i+1; j < 9; j++) {
			if (sum - (height[i] + height[j]) == 100) {
				height[i] = -1;
				height[j] = -1;
				find = true;
				break;
			}
		}
		if (find) break;
	}
	sort(height.begin(), height.end());
	for (int i =2; i < 9; i++) {
		cout << height[i]<<"\n";
	}
}
