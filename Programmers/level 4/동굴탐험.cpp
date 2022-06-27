#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;


void dfs(vector<vector<int>> &temp, vector<vector<int>> &graph, vector<bool> &visited, int current) {
    visited[current]=true;
    for (int i=0; i<temp[current].size(); i++) {
        if (visited[temp[current][i]]) continue;
        graph[current].push_back(temp[current][i]);
        dfs(temp, graph, visited, temp[current][i]);
    }
}

vector<int> topologicalSort(int n, vector<vector<int>> &graph, vector<int> &indegree) {
    queue<int> q;
    vector<int> result;
	q.push(0);
    while (!q.empty()){
        int current=q.front();
        q.pop();
        result.push_back(current);
        for (int i=0; i<graph[current].size(); i++) {
            int next=graph[current][i];
            if (--indegree[next]==0) q.push(next);
        }
    }
    return result;
}

bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {
    bool answer = true;
    vector<int> indegree(n, 0);
    vector<vector<int>> temp(n, vector<int>(0));
    vector<vector<int>> graph(n, vector<int>(0));
    
    for (int i=0; i<path.size(); i++) {
        temp[path[i][0]].push_back(path[i][1]);
        temp[path[i][1]].push_back(path[i][0]);
    }
    
    //양방향 그래프를 단방향 그래프로 바꿔줌
    vector<bool> visited(n, false);
    dfs(temp, graph, visited, 0);
    
    //추가적으로 순서가 존재하는 애들을 그래프에 연결
    for (int i=0; i<order.size(); i++) {
        graph[order[i][0]].push_back(order[i][1]);
    }
    
    //indegree 배열 초기화
    for (int i=0; i<graph.size(); i++) {
        for (int j=0; j<graph[i].size(); j++) {
            indegree[graph[i][j]]++;
        }
    }

    vector<int> result=topologicalSort(n, graph, indegree);
    
	  if (result.size()==n) return true;
    else return false;
}
