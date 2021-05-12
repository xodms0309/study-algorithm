function solution(absolutes, signs) {
    var answer = 123456789;
    answer=absolutes.reduce((acc, cur, i)=>{
        if (signs[i]===true) return acc+cur;
        else return acc-cur;
    }, 0) //초기값을 0으로 설정하는거 잊지 말기
    return answer;
}
