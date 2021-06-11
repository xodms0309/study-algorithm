function solution(n){
    var answer = 0;
    answer=n.toString().split('').map(i=>parseInt(i)).reduce((acc, cur)=>acc+=cur);
    return answer;
}
