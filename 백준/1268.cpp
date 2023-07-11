#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> students(n, vector<int>(n,0));
    
    for (int i=0; i<n; i++) {
        for (int j=0; j<5; j++) {
            cin >> students[i][j];
        }
    }
    
    map<int ,int> same_class;
    
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            for (int k=0; k<5; k++) {
                int me = students[i][k];
                int you = students[j][k];
                if (me==you) {
                    same_class[i]+=1;
                    break;
                }
            }
        }
    }
    
    int max=0;
    int president=0;
    
    for (auto iter: same_class) {
        if (iter.second > max) {
            president=iter.first;
            max=iter.second;
        }
    }
    
    cout << president+1;
    
    
    
}
