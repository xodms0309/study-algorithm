#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool cross(vector<int> &stones, int mid, int k) {
    //사라진 돌의 개수
    int stone=0;
    for (int i=0; i<stones.size(); i++) {
        if (stones[i]<mid) {
            stone++;
            //사라진 돌의 연속된 개수가 k와 같다면 건널 수 없음
            if (stone==k) return false;
        }
        else {
            stone=0;
        }
    }
    return true;
}

int solution(vector<int> stones, int k) {
    int answer = 0;
    int left=0;
    int right=*max_element(stones.begin(), stones.end());
    while (left<=right) {
        int mid=(left+right)/2;
        if (cross(stones, mid, k)) {
            answer=max(answer, mid);
            left=mid+1;
        }
        else {
            right=mid-1;
        }

    }
    return answer;
}
