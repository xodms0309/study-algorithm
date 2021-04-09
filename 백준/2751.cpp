#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int n;
    int entered;
    vector<int> v;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &entered);
        v.push_back(entered);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
        printf("%d\n", v[i]);
    }
}