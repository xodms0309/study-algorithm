function ranking(n){
    if (n===0) return 6;
    else return 7-n;
}
function solution(lottos, win_nums) {
    let answer = [];
    let zeroCnt=lottos.filter(lotto=>lotto===0).length;
    let correctCnt=lottos.filter(lotto=>win_nums.includes(lotto)).length;
    answer.push(ranking(zeroCnt+correctCnt), ranking(correctCnt))
    return answer;
}
