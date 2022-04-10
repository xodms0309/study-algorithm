#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int P, L, V;
	int cnt = 1;
	while (true) {
		cin >> L >> P >> V;
		if (!L || !P || !V) break;
		int a, b = 0;
		//몫*L은 온전히 곱할 수 있음
		a = V / P; // a*L
		//나머지가 L보다 크다면 그냥 L만 더해줌
		if (V % P >= L) {
			b = L;
		}
		else b = V % P;
		int day = a * L + b;
		cout << "Case " << cnt << ": " << day << "\n";
		cnt++;
	}
}	
