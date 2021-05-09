function solution(n, lost, reserve) {
    var answer = 0;
    for (let i=0; i<lost.length; i++){
        if (reserve.includes(lost[i])) {
            const index=reserve.indexOf(lost[i]);
            lost.splice(i, 1);
            reserve.splice(index,1);
            i--;
        }
    }
    for (let i=0; i<lost.length; i++){
        if (reserve.includes(lost[i]+1)) {
            const index=reserve.indexOf(lost[i]+1);
            lost.splice(i, 1);
            reserve.splice(index,1);
            i--;
        }
        else if (reserve.includes(lost[i]-1)) {
            const index=reserve.indexOf(lost[i]-1);
            lost.splice(i, 1);
            reserve.splice(index,1);
            i--;
        }
        else
            continue;
    }
    answer=n-lost.length;
    return answer;
}
