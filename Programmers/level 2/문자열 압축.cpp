#include <string>
#include <vector>
using namespace std;

int solution(string s) {
    int answer = s.length();
    //최대로 압축할 수 있는 길이는 1~s.length()/2만큼!
    for (int i=1; i<=s.length()/2; i++) {
        int cnt=1;
        string temp="";
        string cur=s.substr(0, i);
        for (int j=i; j<s.length(); j+=i) {
            string next=s.substr(j, i);
            if (cur==next) cnt++;
            else {
               if (cnt>1) temp+=to_string(cnt);
                temp+=cur;
                cnt=1; 
                cur=next;
            }
        }
        if (cnt>1) temp+=to_string(cnt); 
        temp+=cur;
        if (answer>temp.length()) answer=temp.length();
    }
    return answer;
}
