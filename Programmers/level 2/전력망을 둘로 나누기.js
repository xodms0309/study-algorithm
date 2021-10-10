function solution(n, wires) {
    var answer = 0;
    const graph = [...Array(n + 1)].map(() => [...Array(n + 1)].map(() => 0));
    const visited = Array(n + 1).fill(false);
    let cnt=0;
    const dfs=(v)=>{
        visited[v]=true;
        cnt++;
        for (let i=1; i<=n; i++){
            if (graph[v][i]&&!visited[i]) dfs(i);
        }
    }
    wires.forEach(([v1, v2])=>{
        graph[v1][v2]=1;
        graph[v2][v1]=1;
    })
    
    return wires.reduce((answer,[v1, v2])=>{
        graph[v1][v2]=0;
        graph[v2][v1]=0;
        dfs(1);
        graph[v1][v2]=1;
        graph[v2][v1]=1;
        answer= Math.min(answer, Math.abs(n - 2 * cnt));
        visited.forEach((_, i) => visited[i] =false);
        cnt = 0;
    return answer;
},n);
}
