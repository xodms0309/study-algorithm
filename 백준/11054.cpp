
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
    
    //앞에서부터 증가하는 수열
    //1 5 2 1 4 3 4 5 2 1
    vector<int> dp_left(n, 1);
    for (int i=1; i<n; i++) {
        for (int j=0; j<i; j++) {
            if (arr[i]<=arr[j]) continue;
            dp_left[i]=max(dp_left[i], dp_left[j]+1);
        }
    }
    
    //뒤에서부터 증가하는 수열
    vector<int> dp_right(n, 1);
    for (int i=n-2; i>=0; i--) {
        for (int j=n-1; j>=i; j--) {
            if (arr[i]<=arr[j]) continue;
            dp_right[i]=max(dp_right[i], dp_right[j]+1);
        }
    }
    int answer=0;
    for (int i=0; i<n; i++) {
        answer=max(answer, dp_left[i]+dp_right[i]-1);
    }
    cout << answer;
}
