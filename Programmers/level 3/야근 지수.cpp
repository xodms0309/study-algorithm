#include <string>
#include <vector>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
	priority_queue<int, vector<int>> pq(works.begin(), works.end()); //계속해서 최대값을 갱신해줘야하기 때문에 pq 사용
    while (n>0) {
        int num=pq.top();
        pq.pop();
        pq.push(num-1);
        n--;
    }
    
    while (!pq.empty()) {
        int num=pq.top();
        pq.pop();
        if (num<0) continue;
        answer+=num*num;
    }

    return answer;
}
