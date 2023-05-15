#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n, k;
    cin >> n >>k;
    vector<int>pie(n);
    
    for (int i=0; i<n; i++) {
        cin >> pie[i];
    }
    for (int i=0; i<k-1; i++) {
        pie.push_back(pie[i]);
    }
    
    int sum=0;
    int max_pie=0;
    
    for (int i=0; i<k; i++) {
        sum+=pie[i];
    }
    
    max_pie=sum;
    
    for (int i=k; i<pie.size(); i++) {
        int next=sum+pie[i]-pie[i-k];
        sum = next;
        max_pie=max(max_pie, next);
    }
    
    cout << max_pie;
    
}
