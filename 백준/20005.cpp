#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, -1, 1};

typedef pair<int, int> pi;
typedef pair<char, int> ci;

int m, n, p;

struct Point {
    int x;
    int y;
    int cnt;
};

int bfs(vector<vector<char>> &graph, pi start) {
    int x = start.first;
    int y = start.second;
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    queue<Point> q;
    
    visited[x][y]=true;
    q.push({x, y, 0});
    
    while (!q.empty()) {
        int currentX = q.front().x;
        int currentY = q.front().y;
        int cnt = q.front().cnt;
        q.pop();
        
        if (graph[currentX][currentY]=='B') {
            return cnt;
        }
        
        for (int i=0; i<4; i++) {
            int nextX = currentX+dx[i];
            int nextY = currentY+dy[i];
            
            if (nextX<0 || nextX>=m || nextY<0 || nextY>=n) continue;
            if (visited[nextX][nextY] || graph[nextX][nextY]=='X') continue;
            
            q.push({nextX, nextY, cnt+1});
            visited[nextX][nextY] = true;
        }
    }
    
    return 0;
}

pi findStart(vector<vector<char>> &graph, char id) {
    for (int i=0; i< m; i++) {
        for (int j=0; j<n; j++) {
            if (graph[i][j]==id) {
                return {i, j};
            }
        }
    }
    return {0, 0};
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> m >> n >> p;
    vector<vector<char>> graph(m, vector<char>(n));
    
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            cin >> graph[i][j];
        }
    }
    
    vector<ci> players(p);
    
    for (int i=0; i<p; i++) {
        cin >> players[i].first >> players[i].second;
    }
    int hp;
    cin >> hp;
    
    vector<int> attackTime(p);
    
    for (int i=0; i<p; i++) {
        char id = players[i].first;
        int attack = players[i].second;
        pi start = findStart(graph, id);
        
        int arriveTime = bfs(graph, start);
        attackTime[i]=arriveTime;
    }
    
    int currentTime=0;
    
    set<char> s;
    
    while (hp>=0) {
        for (int i=0; i<p; i++) {
            if (attackTime[i]<=currentTime) {
                s.insert(players[i].first);
                hp-=players[i].second;
            }
        }
        currentTime++;
    }
    
    cout << s.size();
}
