#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool check(string user, string banned){
    for (int i=0; i<banned.length(); i++){
        if (banned[i]=='*') continue;
        if (banned[i]!=user[i]) return false;
    }
    return true;
}
bool isSame(vector<string> users, vector<string>banned){
    int len=banned.size();
    do{
        for (auto iter: users) {
            cout << iter;
        }
        bool flag=false;
        for (int i=0; i<len; i++) {
            if (banned[i].length()!=users[i].length() || !check(users[i], banned[i])) {
                flag=true;
                break;
            }
        }
        if (!flag) return true;
    }while (next_permutation(users.begin(), users.end()));
    return false;
}
int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    //banned_id 배열과 같은 길이를 가진 배열을 다 만들고 조건에 부합하는지 확인
    vector<bool>temp(user_id.size(), false);
    for (int i=0; i<banned_id.size(); i++) {
        temp[i]=true;
    }
    int cnt=0;
    vector<vector<string>> combinations;
    do{
        cnt++;
        vector<string> users; 
        for (int i=0; i<temp.size(); i++){
            if (temp[i]) users.push_back(user_id[i]);
        }
        sort(users.begin(), users.end());
        //combinations 배열에 user 조합 저장
        combinations.push_back(users);
    } while (prev_permutation(temp.begin(), temp.end()));
    //처음 풀었을 땐 그냥 user이랑 banned 둘 다 정렬해서 매치를 했는데 생각해보니까 그렇게 풀면 *****이런 경우를 못잡아냄
    //조합을 만들어준 걸 또 조합시킴
    //ex) [frodo, fradi]는 [fradi, frodo]로도 탐색해야됨
    for (int i=0; i<combinations.size(); i++){
        if (isSame(combinations[i], banned_id)) answer++;
    }
    return answer;
}
