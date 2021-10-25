function solution(n) {
    var answer = 0;
    let i=1;
    while (true){
        const remainder=n%i;
        if (remainder==1) break;
        i++;
    }
    return i;
}
