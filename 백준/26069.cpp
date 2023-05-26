#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    int n;
    set<string> s;
    cin >> n;
    for (int i=0; i<n; i++) {
        string a, b;
        cin >> a >> b;
        if (a=="ChongChong" || b=="ChongChong") {
            s.insert(a);
            s.insert(b);
            continue;
        }
        if (s.find(a)!=s.end() || s.find(b)!=s.end()) {
            s.insert(a);
            s.insert(b);
        }
    }
    cout << s.size();
}
