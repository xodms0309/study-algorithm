#include <string>
#include <vector>
#include <map>
#include <tuple>
#include <algorithm>
#include <iostream>

using namespace std;
typedef tuple<int, string, int> tp;
map<string, int> m;

bool cmp(const tp &a, const tp &b) {
    //장르 정렬
    if (m[get<1>(a)] != m[get<1>(b)]) return m[get<1>(a)] > m[get<1>(b)];
    //재생횟수 정렬
    if (get<2>(a) != get<2>(b)) return get<2>(a) > get<2>(b);
    //고유 번호 정렬
    return get<0>(a) < get<0>(b);
}

bool cmp2 (const pair<string,int> &a, const pair<string,int> &b) {
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    vector<tp> v;
    
    for (int i=0; i<genres.size(); i++) {
        //고유번호, 장르, 재생횟수
        v.push_back({i, genres[i], plays[i]});
    }
    
    for (int i=0; i<genres.size(); i++) {
        m[genres[i]]+=plays[i];
    }
    //각 장르 전체 재생횟수대로 정렬
    vector<pair<string,int>> vec(m.begin(), m.end());
    sort(vec.begin(), vec.end(), cmp2);
    
    sort(v.begin(), v.end(), cmp);
    
    for (auto [g, _]: vec) {
        int cnt=0;
        for (auto [i, genre, play]: v) {
            if (cnt<2 && genre==g) {
                answer.push_back(i); 
                cnt++;
            }
        }
    }
    
    return answer;
}
