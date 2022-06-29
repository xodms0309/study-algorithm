#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iostream>

using namespace std;
typedef pair<string ,int> pi;

vector<string> splitStr(string str) {
    istringstream iss(str);
    string buffer;
 
    vector<string> result;
 
    while (getline(iss, buffer, ',')) {
        result.push_back(buffer);
    }
 
    return result;
}

string replaceAll(string &str, const string& from, const string& to) {
	int pos=0;
    while((pos=str.find(from))!=-1) {
        str.replace(pos, from.length(), to);
    }
    return str;
}

string convertMelody(string str) {
    str=replaceAll(str, "A#", "a");
    str=replaceAll(str, "C#", "c");
    str=replaceAll(str, "D#", "d");
    str=replaceAll(str, "F#", "f");
    str=replaceAll(str, "G#", "g");
    
    return str;
}


string solution(string m, vector<string> musicinfos) {
    string answer = "";
    pi candidate={"", 0};
    for (int i=0; i<musicinfos.size(); i++) {
        vector<string> music=splitStr(musicinfos[i]);
        int start_h=stoi(music[0].substr(0, 2));
        int start_m=stoi(music[0].substr(3, 2));
        int end_h=stoi(music[1].substr(0,2));
        int end_m=stoi(music[1].substr(3,2));
        
        string title=music[2];
        string melody=convertMelody(music[3]);
        
        //재생된 시간
        int played_time=(end_h-start_h)*60+(end_m-start_m);
       	int melody_time=melody.length();
        
        if (played_time>melody_time){
            int diff=played_time/melody_time-1;
            int mod=played_time%melody_time;
            while (diff--) {
                melody+=melody;
                if (melody.length()>m.length()) break;
            }
            melody+=melody.substr(0, mod);
        }
        else {
            melody=melody.substr(0, played_time);
        }
        
        if (melody.find(convertMelody(m))!=string::npos) {
            if (candidate.second==0) candidate={title, played_time};
            else {
                if (candidate.second < played_time) {
                    candidate={title, played_time};
                }
            }
        }
        
    }
    if (candidate.second==0) return "(None)";
    return candidate.first;
}
