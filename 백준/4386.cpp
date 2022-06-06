#include <iostream>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;
typedef pair<double, int> di;
const int INF=1e5;

double prim(int n, int start, vector<vector<di>> &graph){
    priority_queue <di, vector<di>, greater<>>pq;
    vector<bool> visited(n, false);
    vector<double>dist(n, INF);
    
    //초기화
    dist[start]=0;
    pq.push({0, start});
    
    double sum=0;
    while (!pq.empty()) {
        auto[current_weight, current]=pq.top();
        pq.pop();
        
        if (visited[current]) continue;
        
        visited[current]=true;
        sum+=current_weight;
        
        for (auto[next_weight, next]:graph[current]) {
            if (!visited[next] && next_weight<dist[next]) {
                dist[next]=next_weight;
                pq.push({next_weight, next});
            }
        }
    }
    return sum;
}

int main(){
    int n;
    cin >> n;
    
    vector<pair<double, double>> star;
    vector<vector<di>> graph(n, vector<di>(0));
    
    double x, y;
    for (int i=0; i<n; i++) {
        cin >> x >> y;
        for (int j=0; j<i; j++) {
            double dx=x-star[j].first;
            double dy=y-star[j].second;
            double dist=sqrt(dx*dx+dy*dy);
    
            graph[i].push_back({dist, j});
            graph[j].push_back({dist, i});
        }
        star.push_back({x, y});
    }
    cout << fixed;
    double result=prim(n, 0, graph);
    cout.precision(2);
    cout <<result;
}
