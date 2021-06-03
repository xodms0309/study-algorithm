function solution(n) {
    var answer = 0;
    let l=n.length;
    n=n.toString(3).split('').map(i=>parseInt(i)).reduce((acc, cur, i)=>{
        return acc+cur*Math.pow(3, i);
    },0);
    return n;
}
