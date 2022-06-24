#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
typedef pair<long long, int> pi;

bool cmp(const pi &a, const pi &b) {
    return a.second<b.second;
}

int solution(vector<int> food_times, long long k) {
    int answer = 0;
    vector <pi> food;
    long long sum=0;
    for (int i=0; i<food_times.size(); i++) {
        //몇 번 음식인지 기억할 수 있도록
        food.push_back({food_times[i], i+1});
        sum+=food_times[i];
    }
    
    //더 먹어야 하는 음식이 없을 때
    if (sum<=k) return -1;
    
    //pop_back을 사용하기 위해 내림차순으로 정렬한다.
    sort(food.begin(), food.end(), greater<>());
    
    long long pre_val=0;
    while (true) {
        int num_food=food.size();
        //가장 시간이 적게 걸리는 음식
        long long min_val=food.back().first;
        if ((min_val-pre_val)*num_food<k) {
            //k*min_val만큼의 시간이 흐름
            k-=(min_val-pre_val)*num_food;
            pre_val=min_val;
            food.pop_back(); //erase를 쓰면 시간 초과 ..
        }
        else break;
    }
    
    //다시 인덱스로 정렬
    sort(food.begin(), food.end(), cmp);
	return food[k%food.size()].second;
}
