function solution(k, dungeons) {
    var answer = -1;
    let visited=Array(dungeons.length + 1).fill(false);
    const dfs=(k, cnt)=>{
        for (let i=0; i<dungeons.length; i++){
            if (!visited[i]&&dungeons[i][0]<=k) {
                visited[i]=true;    
                dfs(k-dungeons[i][1], cnt+1);
                visited[i]=false;
            }
        }
        answer=Math.max(answer, cnt);
    }
    dfs(k, 0);
    return answer;
}
