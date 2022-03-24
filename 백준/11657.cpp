#include <iostream>
#include <vector>
using namespace std;
const int INF = 987654321;
typedef pair<int, int> pi;
long long dist[501];
vector<pair<pi, int>> graph;
void bellmanford(int N) {
    dist[1] = 0;
    for (int i = 1; i <= N - 1; i++) {
        for (int j = 0; j < graph.size(); j++) {
            int start = graph[j].first.first;
            int end = graph[j].first.second;
            int cost = graph[j].second;
            //방문하지 않았던 정점이면 계산 안함
            if (dist[start] == INF) continue;
            if (dist[end] > dist[start] + cost) {
                dist[end] = dist[start] + cost;
            }
        }
    }
    for (int i = 0; i < graph.size(); i++) {
        int start = graph[i].first.first;
        int end = graph[i].first.second;
        int cost = graph[i].second;
        if (dist[start] == INF) continue;
        if (dist[end] > dist[start] + cost) {
            //값이 갱신되면 음수가 존재하므로 
            cout << -1;
            return;
        }
    }    
    for (int i = 2; i <= N; i++) {
        if (dist[i] == INF) cout << "-1\b";
        else cout << dist[i] << "\n";
    }
}
int main()
{
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        //a에서 b까지 가는데 c시간
        graph.push_back(make_pair(make_pair(a, b), c));
    }
    for (int i = 1; i <= N; i++) {
        dist[i] = INF;
    }
    bellmanford(N);    

}
