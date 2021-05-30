function solution(numbers) {
    var answer = [];
    let num=0;
    for (let i=0; i<numbers.length-1;i++){
        for (let j=i+1; j<numbers.length; j++){
            num=numbers[i]+numbers[j];
            if (answer.includes(num)) continue;
            else answer.push(num);
        }
    }
    answer.sort((a,b)=>a-b);
    return answer;
}
