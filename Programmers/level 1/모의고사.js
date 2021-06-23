function solution(answers) {
    let answer = [];
    let firstArray=[1,2,3,4,5];
    let secondArray=[2,1,2,3,2,4,2,5];
    let thirdArray=[3,3,1,1,2,2,4,4,5,5];

    const correct=(answers, array)=>{
        return answers.filter((elem, i)=>(elem===array[i%array.length])).length;
    }
    let first=correct(answers,firstArray);
    let second=correct(answers,secondArray);
    let third=correct(answers,thirdArray);
    
    const max=Math.max(first, second, third);
    
    if (max===first) answer.push(1);
    if (max===second) answer.push(2);
    if (max===third) answer.push(3);
    
    return answer;
}
