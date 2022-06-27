#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> release;
    int n = progresses.size();
    for (int i=0; i<n; i++) {
        release.push_back(ceil(double(100-progresses[i])/speeds[i]));
    }
    
    int day=0;
    
    for (int i=0; i<n; i++) {
        if (release[i]>day) {
            answer.push_back(1);
            day=release[i];
        }
        else {
            answer.back()++;
        }
    }

    return answer;
}
