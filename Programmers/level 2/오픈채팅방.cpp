#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <iostream>
using namespace std;

vector<string> solution(vector<string> records) {
    vector<string> answer;
    map<string, string> users;
    for (auto record: records) {
        vector<string> result;
    	stringstream ss(record);
    	string temp;

    	while (getline(ss, temp, ' ')) {
        	result.push_back(temp);
    	}
        
        string cmd=result[0];
        string id=result[1];
        string name=temp;
        //cout << cmd << id << name <<"\n";
        if (cmd=="Enter") {
            if (users.find(id)!=users.end()) {
                users.at(id)=name;
            }
            else users.insert({id, name});
        }
        else if (cmd=="Change") {
            users.at(id)=name;
        } 
    }
    
    for (auto record: records) {
        vector<string> result;
    	stringstream ss(record);
    	string temp;

    	while (getline(ss, temp, ' ')) {
        	result.push_back(temp);
    	}
        
        string cmd=result[0];
        string id=result[1];
        
        if (cmd=="Enter") {
            answer.push_back(users.at(id)+"님이 들어왔습니다.");
        }
        else if (cmd=="Leave") {
            answer.push_back(users.at(id)+"님이 나갔습니다.");
        } 
    }
    
    return answer;
}
