#include <string>
#include <vector>
#include <queue>

using namespace std;
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
bool bfs(int x, int y, vector<string> &arr){
    vector<vector<bool>>visited(5, vector<bool>(5,false));
    queue<pair<pair<int, int>, int>> q;
    q.push(make_pair(make_pair(x,y),0));
    visited[x][y]=true;
    while (!q.empty()) {
        int currentX=q.front().first.first;
        int currentY=q.front().first.second;
        int dist=q.front().second;
        q.pop();
        if (dist==2) continue;
        for (int i=0; i<4; i++) {
            int nextX=currentX+dx[i];
            int nextY=currentY+dy[i];
            //범위 벗어나는 경우
            if (nextX<0 || nextX>=5 || nextY<0 || nextY>=5) continue;
            //이미 방문한 경우와 파티션으로 막힌 경우
            if (visited[nextX][nextY] || arr[nextX][nextY]=='X') continue;
            //만약 빈 테이블이 있다면 그 옆에 사람이 있는지도 확인해봐야 함
            if (arr[nextX][nextY]=='O') {
                visited[nextX][nextY]=true;
                q.push(make_pair(make_pair(nextX, nextY),dist+1));
            }
            if (arr[nextX][nextY]=='P') return false;
        }
    }
    return true;
}
int findAnswer(vector<string> arr){
    for (int i=0; i<5; i++) {
        for (int j=0; j<5; j++) {
            if (arr[i][j]=='P') {
                if (bfs(i, j, arr)==false) return 0;
            } 
        }
    }
    return 1;
}
vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for (int i=0; i<places.size(); i++) {
        answer.push_back(findAnswer(places[i]));
    }

    return answer;
}
