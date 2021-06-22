/*처음에 dp로 풀었다가 시간 초과난 .. 이렇게 간단했다니*/
function solution(n){
    var ans = [];
    let cnt=0;
    while (n>0){
        if (n%2!=0) cnt++;
        n=Math.floor(n/2);
    }
    return cnt;
}
