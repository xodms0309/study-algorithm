/*첫 풀이*/
function solution(a, b) {
    var answer=0;
    for (let i=0; i<a.length;i++){
      answer+=a[i]*b[i];
    }
    return answer;
}

/*js스럽게 풀어보기*/
function solution(a, b) {
    var answer=0;
    answer=a.reduce((acc,cur, i)=>acc+=cur*b[i],0);
    return answer;
}
