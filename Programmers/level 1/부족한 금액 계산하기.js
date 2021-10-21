function solution(price, money, count) {
    var answer = -1;
    let sum=0;
    let payment=0;
    for (let i=1; i<=count; i++){
        payment=price*i;
        sum+=payment;
    }
    if (money-sum>=0) return 0;
    else return sum-money;
}
