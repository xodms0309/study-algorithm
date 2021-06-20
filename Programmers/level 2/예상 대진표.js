function solution(n,a,b){
    let round=0;
    const isPower=(n)=>{
        if (n%2===0) return true;
        else return false;
    } //2의 제곱인지 판별
    while (Math.ceil(a)!=Math.ceil(b)){ //a와 b를 반올림한게 같을 때 같은 라운드에서 만남
        if (isPower(a)) a/=2;
        else a=(a+1)/2;
        if (isPower(b)) b/=2;
        else b=(b+1)/2;
        round++;
    }
    return round;
}
