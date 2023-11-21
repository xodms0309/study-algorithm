#include <iostream>
#include <vector>

using namespace std;

int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, -1, 1};
int n, m;

typedef pair<int, int> pi;

vector<vector<bool>> visited(3, vector<bool>(3, false));
vector<pi> result;

int calculate(vector<vector<char>> &graph, vector<pi> &result) {
    int sum=graph[result[0].first][result[0].second]-'0';
    
    for (int i=1; i<result.size(); i+=2) {
        int x = result[i].first;
        int y = result[i].second;
        
        char op = graph[result[i].first][result[i].second];
        int num = graph[result[i+1].first][result[i+1].second]-'0';
        if (op=='-') sum-=num;
        else sum+=num;
    }
    
    return sum;
}

void dfs(vector<vector<char>> &graph, vector<pi> v, int currentX, int currentY, bool isNumber) {
    if (v.size()==m*2-1) {
        if (calculate(graph, v)==n) {
            result=v;
        }
    }
    
    for (int i=0; i<4; i++) {
        int nextX = currentX+dx[i];
        int nextY = currentY+dy[i];
        
        if (nextX<0 || nextX>=3 || nextY<0 || nextY>=3) continue;
        if (visited[nextX][nextY]) continue;
        
        if (isNumber) {
            //이전에 숫자였으면 다음은 연산자여야 함
            if (graph[nextX][nextY]!='+' && graph[nextX][nextY]!='-') continue;
            v.push_back({nextX, nextY});
            visited[nextX][nextY] = true;
            dfs(graph, v,nextX, nextY, false);
            v.pop_back();
            visited[nextX][nextY] = false;
        }
        else {
            if (graph[nextX][nextY]=='+' || graph[nextX][nextY]=='-') continue;
            v.push_back({nextX, nextY});
            visited[nextX][nextY] = true;
            dfs(graph, v,nextX, nextY, true);
            v.pop_back();
            visited[nextX][nextY] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    vector<vector<char>> graph(3, vector<char>(3));
    
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            cin >> graph[i][j];
        }
    }
    
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            if (graph[i][j]=='+' || graph[i][j]=='-') continue;
            vector<pi> temp;
            temp.push_back({i, j});
            visited[i][j]=true;
            dfs(graph, temp, i, j, true);
            temp.pop_back();
            visited[i][j]=false;
        }
    }
    
    if (result.size()==0) {
        cout << 0;
    }
    else {
        cout << 1<<"\n";
        for (int i=0; i<result.size(); i++) {
            cout <<result[i].first << " " << result[i].second << "\n";
        }
    }
    
}
