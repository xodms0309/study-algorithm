#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<int>parent;

bool cmp(const vector<int> &a, const vector<int> &b) {
    return b[2]>a[2];
}

int findParent(int x) {
    if (parent[x] < 0) return x;
    return parent[x]=findParent(parent[x]);
}

bool unionNodes(int x, int y) {
    int px=findParent(x);
    int py=findParent(y);
    if (px==py) return false;
    
    if (parent[px]>parent[py]) {
        parent[px]+=parent[py];
        parent[py]=px;
    }
    else {
        parent[py]+=parent[px];
        parent[px]=py;
    }
    return true;
}

int kruskal(int n, vector<vector<int>> &costs) {
    int sum=0;
    int cnt=0;

    for (int i=0; i<costs.size(); i++) {
        int a=costs[i][0];
        int b=costs[i][1];
        int c=costs[i][2];
       // auto [a, b, c] = costs[i];
        if (!unionNodes(a, b)) continue;
        sum+=c;
        cnt++;
        if (cnt==n-1) return sum;
    }
    return 0;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    parent.assign(n, -1);
    sort(costs.begin(), costs.end(), cmp);
    answer=kruskal(n, costs);
    return answer;
}
