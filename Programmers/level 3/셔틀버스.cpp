#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int convertTime(string time) {
    int hour=stoi(time.substr(0,2));
    int min=stoi(time.substr(3, 2));
    return hour*60+min;
}

string numToStr(int time) {
    string hour=to_string(time/60);
    if (time/60<10) hour='0'+hour;
    string min=to_string(time%60);
    if (time%60<10) min='0'+min;
    return hour+":"+min;
}

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";

    int getOn=0;
    
    vector<int> time(timetable.size());
    for (int i=0; i<timetable.size(); i++) {
        time[i]=convertTime(timetable[i]);
    }
    
    sort(time.begin(), time.end());
    
    if (timetable.size()<m) {
        getOn=540+(n-1)*t;
        return numToStr(getOn);
    }
    
    
	int currentTime=540;
    
    //막차 빼고 그 전까지 크루들을 태워서 보냄
    while (n>1) {
        for (int i=0; i<m; i++) {
            if (currentTime>=time[i]) time.erase(time.begin()+i);
            else break;
        }
        n--;
        currentTime+=t;
    }
    
    //만약 차에 탈 수 있는 인원보다 남은 인원이 많다면 m번째 사람보다 1분 빠르게 타야함
    if (time.size()>=m) {
        if (time[m-1]<=currentTime) getOn=time[m-1]-1;
      //m번째 사람이 현재 시간보다 늦게 도착한다면 그냥 버스 시간에 타면 됨
        else getOn=currentTime;
    }
    else getOn=currentTime;
    
    return numToStr(getOn);
}
