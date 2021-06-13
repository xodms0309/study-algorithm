function solution(s){
    var answer = true;
    let stack=[];
    if (s[0]===')') answer=false;
    for (let i=0; i<s.length; i++){
        if (s[i]==='(') stack.push('(');
        else if (s[i]===')') stack.pop();
    }
    if (stack.length!==0) answer=false;
    return answer;
}
