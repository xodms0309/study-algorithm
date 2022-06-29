#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int splitBrace(string str){
    int left=0;
    int right=0;
    int idx=0;
    while (true){
        if (str[idx]=='(') left++;
    	else right++;
        if (left==right) break;
        idx++;
    }
    return idx+1;
}

bool isCorrect(string str){
    stack<char>s;
    for (int i=0; i<str.length(); i++) {
        if (str[i]=='(') s.push(str[i]);
        else {
            if (s.empty()) return false;
            s.pop();
        }
    }
    if (!s.empty()) return false;
    return true;
}

string reverseBrace(string str) {
    string temp="";
    for (int i=0; i<str.length(); i++) {
        if (str[i]=='(') temp+=')';
        else temp+='(';
    }
    return temp;
}

string recursive (string str) {
    if (str=="") return "";
    
    string u=str.substr(0, splitBrace(str));
    string v=str.substr(splitBrace(str));
    string temp="";
    
    if (isCorrect(u)) {
        temp+=u;
        temp+=recursive(v);
        return temp;
    }
    else {
        temp+='(';
        temp+=recursive(v);
        temp+=')';
        u.erase(u.begin());
        u.erase(u.end()-1);
        temp+=reverseBrace(u);
        return temp;
    }
}

string solution(string p) {
    string answer = "";
    answer=recursive(p);
    return answer;
}
