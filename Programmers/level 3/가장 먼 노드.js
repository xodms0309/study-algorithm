function solution(n, edge) {
    let answer = 0;
    let queue=[];
    const graph=Array(n+1).fill(null).map(()=>Array());
    let visited=new Array(n+1).fill(false);
    const dist=new Array(n+1).fill(0);
    edge.forEach(e=>{
        graph[e[0]].push(e[1]);
        graph[e[1]].push(e[0]);
    });
    dist[0]=1;
    const bfs=(v)=>{        
        visited[v]=true;
        queue.push(v);
        while (queue.length){
            let front=queue.shift();
            for (let i=0; i<graph[front].length; i++){
                const next=graph[front][i];
                if (!visited[next]){
                    visited[next]=true;
                    queue.push(next);
                    dist[next]=dist[front]+1;
                }
            }
        }
    }
    bfs(1);
    const max=Math.max(...dist);
    return dist.filter(d=>d===max).length;
}
