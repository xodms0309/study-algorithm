function solution(N, stages) {
    let answer = [];
    let fArray=[];
    let failcnt=[];
    let succnt=[];
    for (let i=1; i<=N; i++){
        succnt=stages.filter(stage=>stage>=i); //클리어 하지 못한 사람들
        failcnt=stages.filter(stage=>stage===i); //클리어 한 사람들+클리어 하지 못한 사람들
        if(succnt.length===0) fArray.push({rate:0, stage:i}); //클리어 한 사람이 없다면 rate을 0으로 설정 
        else fArray.push({rate:failcnt.length/succnt.length, stage:i});
    }
    fArray.sort(function(a,b){
        if(a.rate===b.rate) return a.stage<b.stage? -1:1;  //실패율이 같다면 작은 번호의 스테이지가 먼저 오게
        return a.rate<b.rate? 1:-1;
    });
    for (let i=0; i<N;i++){
        answer.push(fArray[i].stage);
    }
    return answer;
}
