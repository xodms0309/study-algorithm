#include <string>
#include <vector>
#include <map>

using namespace std;


string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    map<char, int> m;
    for (int i=0; i<survey.size(); i++) {
        char disagree=survey[i][0];
        char agree=survey[i][1];
        if (choices[i]==4) continue;
        if (choices[i]>4) {
            //동의가 점수를 얻음
            m[agree]+=(choices[i]-4);
        }
        else if (choices[i]<4) {
            //비동의가 점수를 얻음
            m[disagree]+=(4-choices[i]);
        }
    }
    
    
    answer+=m['R'] >= m['T'] ? 'R':'T';
    answer+=m['C'] >= m['F'] ? 'C':'F';
    answer+=m['J'] >= m['M'] ? 'J':'M';
    answer+=m['A'] >= m['N'] ? 'A':'N';
    
    return answer;
}
