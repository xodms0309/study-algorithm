#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(vector<int> numbers) {
    string answer = "";
    int n=numbers.size();
    vector<pair<string, int>> temp;
    int max_len=0;
    bool flag=true;
	for (int i=0; i<n; i++) {
       if (numbers[i]!=0) flag=false;
       temp.push_back({to_string(numbers[i]), i});
       if (max_len<temp[i].first.length()) 
           max_len=temp[i].first.length();
    }
    
    if (flag) return "0";
    
    int m=6;
    for (int i=0; i<n; i++) {
        while (m--) {
           temp[i].first+=temp[i].first;
        }
        temp[i].first=temp[i].first.substr(0, 6);
    }
    
    sort(temp.begin(), temp.end(), greater<>());
    
    for (int i=0; i<n; i++) {
        answer+=to_string(numbers[temp[i].second]);
    }
    
    return answer;
}
