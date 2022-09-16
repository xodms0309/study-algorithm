#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> pi;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int idx=1;
    for (int i=0; i<stations.size(); i++) {
        int start=stations[i]-w>=0 ? stations[i]-w:0;
        int end=stations[i]+w<n ? stations[i]+w : n;
        
        int len=start-idx;
        answer+=len/(w*2+1);
        if (len%(w*2+1)>0) answer++;
        idx=end+1;
    }
    if (idx<=n) {
        int len=n-idx+1;
        answer+=len/(w*2+1);
        if (len%(w*2+1)>0) answer++;
    }

    return answer;
}
