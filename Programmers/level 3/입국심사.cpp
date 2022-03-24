#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    sort(times.begin(), times.end());
    long long low=1;
    long long high=(long long) times.back()*n;
    while (low<=high){    
        long long cnt=0;
        long long mid=(low+high)/2;
        for (auto i:times) {
            cnt+=mid/i;
        }
        //n보다 cnt가 작으면 시간이 더 필요한 것임
        if (cnt<n) {
            low=mid+1;
        }
        else {
            answer=mid;
            high=mid-1;
        }
    }
    return answer;
}
