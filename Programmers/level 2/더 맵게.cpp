#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<>> pq;

    for (int i=0; i<scoville.size(); i++) {
        pq.push(scoville[i]);
    }
    
    while (pq.size()>=2) {
        int s=0;
        int first=pq.top();
        pq.pop();
        int second=pq.top();
        pq.pop();
        
        answer++;
        s=first+(second*2);
        pq.push(s);
        
        if (pq.top()>=K) return answer;
    }
    return -1;
}
