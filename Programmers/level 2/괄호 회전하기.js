function solution(s) {
    var answer = -1;
    const checkBracket=(s)=>{
        let stack=[];
        let flag=true;
        for (let str of s){
            if (str==='('||str==='['||str==='{') stack.push(str);
            else if (str === ')'){
                if (stack.length===0) {
                    flag=false;
                    break;
                }
                else if (stack[stack.length - 1] === '(') 
                    stack.pop();
			    else {
				    flag = false;
				    break;
			    }
            }
            else if (str === ']'){
                if (stack.length===0) {
                    flag=false;
                    break;
                }
                else if (stack[stack.length - 1] === '[') 
                    stack.pop();
			    else {
				    flag = false;
				    break;
			    }
            }
            else if (str === '}'){
                if (stack.length===0) {
                    flag=false;
                    break;
                }
                else if (stack[stack.length - 1] === '{') 
                    stack.pop();
			    else {
				    flag = false;
				    break;
			    }
            }
        }
        if(!flag||stack.length!==0) return 0;
        else return 1;
    }
    for (let i=0; i<s.length; i++){
        s=s.slice(1)+s[0];
        answer+=checkBracket(s);        
    }
    return answer+1;
}
