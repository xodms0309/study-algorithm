#include <string>
#include <vector>
#include <iostream> 
using namespace std;
const int INF=1e6;

vector<vector<int>> dp;

int solution(int alp, int cop, vector<vector<int>> problems) {
    int answer = 0;
    int max_alp=0;
    int max_cop=0;

    for (int i=0; i<problems.size(); i++) {
        max_alp=max(max_alp, problems[i][0]);
        max_cop=max(max_cop, problems[i][1]);
    }
    
    dp.assign(max_alp+1, vector<int>(max_cop+1, INF)); //dp[alp][cop]

    if (alp>=max_alp && cop>=max_cop) return 0;
    
    //초기 알고력, 코딩력이 최대값보다 클 수 있음
    //여기서 segmentation fault가 일어났음..
    alp=min(max_alp, alp);
    cop=min(max_cop, cop);
    
    dp[alp][cop]=0;
    
    for (int i=alp; i<=max_alp; i++) {
        for (int j=cop; j<=max_cop; j++) {
            if (i+1<=max_alp) 
                dp[i+1][j]=min(dp[i+1][j], dp[i][j]+1);
            if (j+1<=max_cop) 
                dp[i][j+1]=min(dp[i][j+1], dp[i][j]+1);
            for (auto problem: problems) {
                int alp_req=problem[0];
                int cop_req=problem[1];
                int alp_rwd=problem[2];
                int cop_rwd=problem[3];
                int cost=problem[4];

                if (i<alp_req || j<cop_req) continue;
                
                int next_alp=min(max_alp, i+alp_rwd);
                int next_cop=min(max_cop, j+cop_rwd);
                
                dp[next_alp][next_cop]=min(dp[next_alp][next_cop], dp[i][j]+cost);
            }
        }
    }
    
    return dp[max_alp][max_cop];
    
}
