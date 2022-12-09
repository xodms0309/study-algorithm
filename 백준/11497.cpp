#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i=0; i<n; i++) {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        int answer=0;
        answer=max(answer, arr[1]-arr[0]);
        answer=max(answer, arr[n-1]-arr[n-2]);
        
        for (int i=0; i<n-2; i++) {
            answer=max(answer, arr[i+2]-arr[i]);
        }
        cout <<answer <<"\n";
    }
    
    
}
