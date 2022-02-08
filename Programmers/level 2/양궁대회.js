function solution(n, info) {
    let answer = [0,0,0,0,0,0,0,0,0,0,0];
    let max=0;
    const dfs=(apeach, ryan, count, index, ryanBoard)=>{
        if (count>n) return;
        if (index>10){
            let diff=ryan-apeach;
            if (diff>max) {
                ryanBoard[10]=n-count;
                max=diff;
                answer=ryanBoard;
            }
            return;
        }
        if (n>count){
            let temp=[...ryanBoard];
            temp[10-index]=info[10-index]+1;
            dfs(apeach,ryan+index,count+info[10-index]+1, index+1, temp);
        }
        if (info[10-index]>0){
            dfs(apeach+index, ryan, count, index+1, ryanBoard);
        }
        else{
            dfs(apeach, ryan, count, index+1, ryanBoard);
        }
    }
    dfs(0,0,0,0,answer);
    if (max<=0) return [-1];
    else return answer;
}
