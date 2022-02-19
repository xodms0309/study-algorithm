#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int total = 0;
	int maxPeople = 0;
	for (int i = 0; i < 10; i++) {
		int a, b;
		cin >> a >> b;		
		total += b - a;
		maxPeople = max(total, maxPeople);
	}
	cout << maxPeople;
}
