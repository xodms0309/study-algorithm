function solution(n) {
    var answer = 0;
    //문자 풀이
    answer=n.toString().split('').sort((a,b)=>(b-a)).join('');
    return parseInt(answer);
    
    //숫자 풀이
    let tempArr=[];
    let seperateNum=0;
    while (n>0) {
        seperateNum=n%10;
        tempArr.push(seperateNum);
        n=Math.floor(n/=10);
    }
    answer=tempArr.sort((a,b)=>b-a).join('');
    return parseInt(answer);
}
