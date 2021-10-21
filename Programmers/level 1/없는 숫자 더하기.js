function solution(numbers) {
    var answer = -1;
    const numArray=[0, 1, 2, 3, 4, 5, 6, 7, 8, 9];
    answer=numArray.filter(n=>!numbers.includes(n)).reduce((acc, cur)=>acc+cur);
    return answer;
}
