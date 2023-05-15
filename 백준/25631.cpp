#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main(){
    int n;
    cin >> n;
    map<int, int> m;
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        m[x]++;
    }
    
    int max_num=0;
    
    for (auto iter: m) {
        max_num=max(max_num, iter.second);
    }
    
    cout << max_num;

    
}
