#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

int calTime(int total, int defaultTime, int defaultFee, int unitTime, int unitFee){
    if (total<=defaultTime) return defaultFee;
    double parkedTime=double((total-defaultTime))/double(unitTime);
    return defaultFee+ceil(parkedTime)*unitFee;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string, int> parking;
    map<string, int> m;
    for (auto record:records) {
        int hour=stoi(record.substr(0, 2));
        int min=stoi(record.substr(3, 2));
        int time=60*hour+min;
        string car=record.substr(6,4);
        string in_or_out=record.substr(11);
        
        if (in_or_out=="IN") {
       		parking.insert({car, time});
        }
        else {
            auto parkedCar=parking.find(car);
            if (m.find(parkedCar->first)!=m.end()) m.at(parkedCar->first)+=time-parkedCar->second;
            else m.insert({parkedCar->first, time-parkedCar->second});
            parking.erase(parkedCar);
        }
    }
    for (auto car: parking) {
        if (m.find(car.first)!=m.end()) 
            m.at(car.first)+=(1439-car.second);
        m.insert({car.first, 1439-car.second});
    }
    
    for (auto iter:m) {
        answer.push_back(calTime(iter.second, fees[0], fees[1], fees[2], fees[3]));
    }
    
    return answer;
}
