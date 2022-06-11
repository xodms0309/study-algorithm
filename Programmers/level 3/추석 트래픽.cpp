#include <string>
#include <vector>
#include <iostream>

using namespace std;

double convertTime(string line) {
    int hour=stoi(line.substr(0,2));
    int min=stoi(line.substr(3, 2));
    int sec=stoi(line.substr(6, 2));
    double mili=stoi(line.substr(9, 3));
    return hour*3600*1000+min*60*1000+sec*1000+mili;
}

int solution(vector<string> lines) {
    int answer = 0;
    vector<int> start_time;
    vector<int> end_time;
    for (int i=0; i<lines.size(); i++) {
        lines[i].erase(0, 11);
        lines[i].pop_back();
        int process_time=stof(lines[i].substr(13))*1000;
        
        int start=convertTime(lines[i])-process_time+1;
        int end=convertTime(lines[i]);
        start_time.push_back(start);
        end_time.push_back(end);
    }
    
    for (int i=0; i<lines.size(); i++) {
        //최대 처리량을 구하려면 끝나는 지점에서 1초를 더했을 때 겹치는 구간이 몇개인지 확인하면 됨
        int t=end_time[i]+1000;
        int cnt=0;
        for (int j=i; j<lines.size(); j++) {
            if (start_time[j]<t) cnt++;
        }
        answer=max(answer, cnt);
    }

    return answer;
}
