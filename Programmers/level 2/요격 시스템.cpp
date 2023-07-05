#include <string>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> pi;

bool cmp (vector<int> &a, vector<int> &b) {
    if (a[1]==b[1]) return a[0] < b[0];
    return a[1] < b[1];
}

int solution(vector<vector<int>> targets) {
    int answer = 0;
    sort(targets.begin(), targets.end(), cmp);
    int current=0;
    
    for (int i=0; i<targets.size(); i++) {
        if (current <=targets[i][1] && current>targets[i][0]) {
            continue;
        }
        else {
            current=targets[i][1];
            answer++;
        }
    }
    
    return answer;
}
