function solution(number, k) {
    let stack=[];
    number=number.split("");
    stack.push(number[0]);
    for (let i=1; i<number.length; i++){
        while (k!=0&&stack[stack.length-1]<number[i]) {
            stack.pop();
            k--;
        }
        stack.push(number[i]);
    }
    stack=stack.slice(0, stack.length-k); //모든 자리수의 숫자가 똑같을 때
    return stack.join("");
}
