function solution(n, computers) {
    var answer = 0;
    let visited=Array.from(n).fill(0);
    let dfs=(index)=>{
        visited[index]=1;
        for (let j=0; j<n; j++){
            if (computers[index][j]===1){
                if (!visited[j]) {
                    dfs(j);
                }
            }
        }
    }
    for (let i=0; i<n; i++){
        if (!visited[i]) {
            dfs(i);
            answer++;
        }
    }
    dfs(0);
    return answer;
}
