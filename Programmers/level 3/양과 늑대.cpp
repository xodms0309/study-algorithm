#include <string>
#include <vector>
#include <iostream>
using namespace std;
int n;
int answer=1;
vector<bool> visited(17, false);

void dfs(vector<vector<int>> &graph, vector<int> &info, vector<int> &next_node, int node, int sheep, int wolf) {
    if (info[node]==0) sheep++;
    else wolf++;
    
    answer=max(answer, sheep);
    if (wolf>=sheep) return;
    
    //출발 지점 분기
    for (int i=0; i< next_node.size(); i++) {
        vector <int> temp=next_node;
        //방문 처리
        temp.erase(temp.begin()+i);
        //다음에 방문할 수 있는 지점들
        for (int j=0; j<graph[next_node[i]].size(); j++) {
            temp.push_back(graph[next_node[i]][j]);
        }
        dfs(graph, info, temp, next_node[i], sheep, wolf);
    }

}
int solution(vector<int> info, vector<vector<int>> edges) {
    n=info.size();
	vector<vector<int>> graph(n, vector<int>(0));
    vector<int> next_node;
    for (int i=0; i<edges.size(); i++) {
        int a=edges[i][0];
        int b=edges[i][1];
        graph[a].push_back(b);
    }
    for (int i=0; i<graph[0].size(); i++) {
        next_node.push_back(graph[0][i]);
    }
    dfs(graph, info, next_node, 0, 0, 0);
    return answer;
}
