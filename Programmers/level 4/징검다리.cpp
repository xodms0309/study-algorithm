#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    int left=0;
    int right=distance;
    sort(rocks.begin(), rocks.end());
    while (left<=right) {
        int mid=(left+right)/2;
        int cnt=0;
        int prev=0;
        for (int i=0; i<rocks.size(); i++) {
            //사이가 mid보다 작다면 없애도 됨
            if (abs(rocks[i]-prev)<mid) cnt++;
            else prev=rocks[i];
        }

        if (cnt>n) right=mid-1;
        else {
            answer=max(answer, mid);
            left=mid+1;
        }
    }
    return answer;
}
