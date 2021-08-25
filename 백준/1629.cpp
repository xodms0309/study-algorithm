#include <iostream>
using namespace std;

int main() {
    long long A, B, C;
    cin >> A >> B >> C;
    long long res = 1;
    while (B > 0) {
        if (B % 2 == 1) {
            res *= A;
            res %= C;
        }
        A *= (A % C);
        A %= C;
        B /= 2;
    }
    cout << res%C<<"\n";
}
