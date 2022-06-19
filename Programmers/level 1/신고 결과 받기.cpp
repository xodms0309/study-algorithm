#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    int n=id_list.size();
    vector<int> answer(n, 0);
    vector<vector<string>> v(n, vector<string>(0));
    map <string,int> m;
    
    for (int i=0; i<report.size(); i++) {
        vector<string> result;
    	stringstream ss(report[i]);
    	string temp;
    	while (getline(ss, temp, ' ')) {
        	result.push_back(temp);
    	}
        string user=result[0];
        string report=temp;
        
        int idx=find(id_list.begin(), id_list.end(), user)-id_list.begin();
        
        if (find(v[idx].begin(), v[idx].end(), report)!=v[idx].end()) continue;
        
        v[idx].push_back(report);
        m[report]++;
    }
    
    for (int i=0; i<n; i++) {
        for (int j=0; j<v[i].size(); j++) {
            if (m[v[i][j]]>=k) answer[i]++;
        }
    }
    
    return answer;
}
