#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool cmp(const vector<int> &a, const vector<int> &b) {
    if (a[1]==b[1]) return b[0]>a[0];
    return b[1]>a[1];
}

int solution(vector<vector<int>> routes) {
    int answer = 1;
   //차가 나가는 순서로 sort
    sort(routes.begin(), routes.end(), cmp);
    //가장 최근에 설치된 단속 카메라 위치
    int current=routes[0][1];
    for (int i=1; i<routes.size(); i++) {
      //만약 최근 설치된 단속 카메라보다 먼저 들어왔다면 더 설치할 필요x
        if (routes[i][0]<=current) continue;
      //차가 나가는 위치에 단속 카메라 설치
        else {
            current=routes[i][1];
            answer++;
        }
    }
    return answer;
}
