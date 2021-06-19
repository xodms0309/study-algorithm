function solution(n) {
    var answer = '';
    let quotient=n;
    let remainder=0;
    while(quotient!=0){
        remainder=quotient%3;  
        quotient=parseInt(quotient/3);
        if (remainder===0) {
            answer='4'+answer;
            quotient--;
        }
        else if (remainder===1) {
            answer='1'+answer;
        }
        else if (remainder===2) {
            answer='2'+answer;
        }
    }
    return answer;
}

//나중에 꼭 풀이 블로그에 올릴 것
