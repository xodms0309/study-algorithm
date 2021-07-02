function solution(tickets) {
    var answer = [];
    let visited=Array.from(tickets.length).fill(0);
    tickets.sort();

    const route=(current, path, depth)=>{
        if (depth===tickets.length&&answer.length===0){
            //answer.length===0 조건이 들어가는 이유는 알파벳 순서이기 때문에 가장 첫번째 case가 정답임
            answer=path;
            return;
        }
        for (let i=0; i<tickets.length; i++){
            if (visited[i]) continue;
            if (tickets[i][0]===current) {
                visited[i]=1;
                route(tickets[i][1], [...path, tickets[i][1]], depth+1);
                visited[i]=0;
            }
        }
    }
    route('ICN', ['ICN'], 0)
    return answer;
}
