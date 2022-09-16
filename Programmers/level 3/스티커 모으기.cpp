#include <iostream>
#include <vector>
using namespace std;

int solution(vector<int> sticker)
{
    int answer =0;
    int n=sticker.size();
    if (n==1) return sticker[0];
    vector<int> dp(n+1, 0);
    
    //1번 스티커를 뜯는 경우
    dp[0]=sticker[0];
    dp[1]=sticker[0];
    for (int i=2; i<n-1; i++) {
        dp[i]=max(dp[i-2]+sticker[i], dp[i-1]);
    }
    answer=max(answer, dp[n-2]);
    
    //1번 스티커를 안뜯는 경우
    dp[0]=0;
    dp[1]=sticker[1];
     for (int i=2; i<n; i++) {
        dp[i]=max(dp[i-2]+sticker[i], dp[i-1]);
    }
    answer=max(answer, dp[n-1]);
    
    return answer;
}
