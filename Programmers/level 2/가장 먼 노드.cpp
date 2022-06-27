#include <string>
#include <vector>
#include<queue>
#include <algorithm>

using namespace std;
typedef pair<int, int> pi;
vector<pi> result;

vector<int> bfs(int n, vector<vector<int>> &graph) {    
    vector<bool> visited(n+1, false);
    vector<int> dist(n+1, 0);
    queue<int> q;
    
  	visited[1]=true;
    q.push(1);

    while (!q.empty()) {
        int current=q.front();
        q.pop();
        for (int i=0; i<graph[current].size(); i++) {
        	int next=graph[current][i];
        	if (visited[next]) continue;
        	visited[next]=true;
        	dist[next]=dist[current]+1;
            q.push(next);
        }
        cnt++;
    }
    return dist;
}


int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    vector<vector<int>> graph(n+1, vector<int>(0));
    for (int i=0; i<edge.size(); i++) {
        graph[edge[i][0]].push_back(edge[i][1]);
        graph[edge[i][1]].push_back(edge[i][0]);
    }
    
	bfs(n, graph);
    
    vector<int> dist=bfs(n, graph);
    
    int max_dist=*max_element(dist.begin(), dist.end());
    
    
    for (int i=0; i<dist.size(); i++) {
        if (dist[i]==max_dist) answer++;
    }
    
    return answer;
}
