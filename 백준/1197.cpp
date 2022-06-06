#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;
typedef tuple<int,int,int> tp;
vector<int> parent;

int findParent(int x){
    if (parent[x] < 0) {
        return x;
    }
    return parent[x]=findParent(parent[x]);
}

bool unionNodes(int x, int y){
    int px=findParent(x);
    int py=findParent(y);
    
    //사이클이 만들어지는 경우
    if (px==py) {
        return false;
    }
    if (parent[px] < parent[py]) {
        parent[px]+=parent[py];
        parent[py]=px;
    }
    else {
        parent[py]+=parent[px];
        parent[px]=py;
    }
    return true;
}

int kruskal(int v, vector<tp> &edge) {
    int sum=0;
    int cnt=0;
    
    for (auto[w, a, b]: edge){
        if (!unionNodes(a, b)) continue;
        sum+=w;
        cnt++;
        if (cnt==v-1) break;
    }
    return sum;
}

int main(){
    int v, e;
    cin >> v >> e;
    vector<tp> edge;
    parent.assign(v+1, -1);
    for (int i=0; i<e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edge.push_back({c, a, b});
    }
    sort(edge.begin(), edge.end());
    cout << kruskal(v, edge);
}
