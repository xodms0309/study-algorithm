#include <iostream>
#include <vector>

using namespace std;

int calc(int start, int end, vector<int> &arr) {
    int cnt=1;
    for (int i=start; i<=end; i++) {
        cnt*=arr[i];
    }
    return cnt;
}

int main()
{
    int n;
    int answer=0;
    cin >> n;
    vector<int> tree(n);
    for (int i=0; i<n; i++) {
        cin >> tree[i];
    }
    
    for (int i=0; i<n-3; i++) {
        for (int j=i+1; j<n-2; j++) {
            for (int k=j+1; k<n-1; k++) {
                int p = calc(0, i, tree)+calc(i+1, j, tree)+calc(j+1, k, tree)+calc(k+1, n-1, tree);
                if (p > answer) {
                    answer = p;
                }
            }
        }
    }
    
    cout << answer;
    
}
