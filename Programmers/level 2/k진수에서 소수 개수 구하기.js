function solution(n, k) {
    var answer = 0;
    //1. N을 K진수로 변환
    let numArray=n.toString(k).split('0');
    //2. 소수 판별 함수
    const isPrime=(n)=>{
        if (n===1) return false;
        for (let i=2; i<=Math.sqrt(n); i++){
            if (n%i===0) return false;
        }
        return true;
    }
    numArray.map((num)=>{
        if (num==='') return;
        if (isPrime(parseInt(num))) answer+=1;
    })
    return answer;
}
