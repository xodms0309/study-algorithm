#include <iostream>
#include <vector>
using namespace std;

int main() {
	long long A, B;
	cin >> A >> B;
	int cnt = 0;
	while (A) {
		if (A > B) {
			cout << -1;
			break;
		}
		else if (A == B) {
			cout << cnt+1;
			break;
		}
		else {
			if (B % 10 == 1) {
				B -= 1;
				B /= 10;
			}
			else if (B % 2 == 0) {
				B /= 2;
			}
			else {
				cout << -1;
				break;
			}
		}
		cnt++;
	}
}
