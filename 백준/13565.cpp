#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> pi;
int n, m;

int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, -1, 1};

void bfs(vector<vector<int>> &graph, vector<vector<bool>> &visited, int startY){
    int startX=0;
    visited[startX][startY] = true;
    queue<pi> q;
    q.push({startX, startY});
    
    while (!q.empty()) {
        int curX=q.front().first;
        int curY=q.front().second;
        q.pop();
        
        for (int i=0; i<4; i++) {
            int nextX=curX+dx[i];
            int nextY=curY+dy[i];
            
            if (nextX<0 || nextX>=n || nextY<0 || nextY>=m) continue;
            if (visited[nextX][nextY] || graph[nextX][nextY]) continue;
            
            q.push({nextX, nextY});
            visited[nextX][nextY]=true;
        }
    }
}

int main() {
    cin >> n >> m;
    vector<vector<int>> graph(n, vector<int> (m));
    
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            scanf("%1d", &graph[i][j]);
        }
    }

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    
    for (int i=0; i<m; i++) {
        if (graph[0][i]==0) {
            bfs(graph, visited, i);
        }
    }
    
    bool isPercolated = false;
    
    for (int i=0; i<m; i++) {
        if (visited[n-1][i]) {
            isPercolated = true;
        }
    }
    
    if (isPercolated) cout << "YES";
    else cout << "NO";
    
}
