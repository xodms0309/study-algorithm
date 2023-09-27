#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<char>> graph(n, vector<char>(m));
    vector<vector<char>> answer(n, vector<char>(m));
    int count=0;
    
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> graph[i][j];
        }
    }
    
    for (int i=0; i<k; i++) {
        for (int j=0; j<k; j++) {
            map<char, int> alphabet;

            for (int p=i; p<n; p+=k) {
                for (int q=j; q<m; q+=k) {
                    alphabet[graph[p][q]]++;
                }
            }
            
            int max=0;
            char change='A';
            
            for (auto iter: alphabet) {
                if (max<iter.second) {
                    max=iter.second;
                    change=iter.first;
                }
            }
            
            for (int p=i; p<n; p+=k) {
                for (int q=j; q<m; q+=k) {
                    if (graph[p][q]!=change) {
                        count++;
                    }
                    answer[p][q]=change;
                }
            }
        }
    }
    cout << count <<"\n";
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cout << answer[i][j];
        }
        cout << "\n";
    }
}
