#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
bool check(string s, char a, char b, char op, int dist) {
    int a_idx=s.find(a);
    int b_idx=s.find(b);
  
    int real_dist=abs(a_idx-b_idx)-1;
    
    switch(op) {
        case '=': 
            return real_dist==dist;
            break;
        case '<':
            return real_dist<dist;
            break;
        case '>':
            return real_dist>dist;
    }
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    int answer = 0;
    vector<int>v(8,0);
    vector<char> f={'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'};
    for (int i=0; i<8; i++) {
        v[i]=i;
    }
    do{
        bool flag=true;
        string s="";
        for (int i=0; i<8; i++) {
            s+=f[v[i]];
        }
        for (int i=0; i<n; i++){
            char a=data[i][0];
            char b=data[i][2];
            char op=data[i][4];
            int dist=data[i][4]-'0';
            if (check(s,a,b,op,dist)) continue;
            else {
                flag=false;
                break;
            }
        }
        if (flag) answer++;
    }while(next_permutation(v.begin(), v.end()));
    return answer;
}
