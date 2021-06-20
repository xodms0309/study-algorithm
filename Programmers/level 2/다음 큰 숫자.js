function solution(n) {
    var answer = 0;
    let count=0;
    let nextCount=0;
    //n을 이진수로 변환했을 때 1의 수
    count=n.toString(2).split("").filter(i=>i==='1').length;
    while (true){
        n+=1;
        nextCount=n.toString(2).split("").filter(i=>i==='1').length;
        if (nextCount===count) break;
        else continue;
    }
    answer=n;
    return answer;
}
