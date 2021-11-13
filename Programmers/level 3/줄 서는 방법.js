function solution(n, k) {
    var answer = [];
    let arr=new Array(n).fill(1);
    for (let i=1; i<n; i++){
        arr[i]=arr[i-1]+1;
    }
    let factorial=arr.reduce((acc, val)=>acc*val, 1);
    k=k-1;
    while (answer.length!==n){
        factorial=factorial/arr.length;
        let temp=arr[Math.floor(k/factorial)];
        answer.push(temp);
        k=k%factorial;
        arr=arr.filter((num)=>num!==temp);
    }
    return answer;
}
