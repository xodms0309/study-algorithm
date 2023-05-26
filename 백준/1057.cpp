#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int next(int cur) {
    if (cur%2==0) {
        return cur/2;
    }
    return (cur+1)/2;
}

int main() {
    int n, a, b;
    cin >> n >> a >>b;
    int cnt=1;
    
    while (true) {
        if ((a+1)/2==(b+1)/2) {
            cout << cnt;
            break;
        }
        cnt++;
        a=next(a);
        b=next(b);
    }
}
