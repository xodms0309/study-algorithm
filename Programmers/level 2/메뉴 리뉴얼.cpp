#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    //메뉴 개수
    set<char> s;
    for (int i=0; i<orders.size(); i++) {
        for (int j=0; j<orders[i].size(); j++) {
            s.insert(orders[i][j]);
        }
    }
    
    vector<char> temp(s.begin(), s.end());
    //조합을 구하기 위한 sort
    sort(temp.begin(), temp.end());
    
    for (int i=0; i<course.size(); i++) {
        vector<pair<int, string>> candidate;
        int n=course[i];
        vector<bool> comb(temp.size(), false);
        for (int j=0; j<n; j++) comb[j]=true;
        int max_order=0;
        do {
            string str="";
            int cnt=0;
            
            for (int j=0; j<temp.size();j++) {
                if (comb[j]) str+=temp[j];
            }
            
            for (int j=0; j<orders.size(); j++) {
                bool flag=true;
                for (int k=0; k<str.length(); k++) {
                    if (orders[j].find(str[k])==string::npos) {
                        flag=false; 
                        break;
                    }
                }
                if (flag) cnt++;
            }
            
            candidate.push_back({cnt, str});
            max_order=max(max_order, cnt);
            
        }while(prev_permutation(comb.begin(), comb.end()));
        
        for (int i=0; i<candidate.size(); i++) {
            if (candidate[i].first==max_order && max_order>=2) answer.push_back(candidate[i].second);
        }
        
    }
    sort(answer.begin(), answer.end());
    return answer;
}
