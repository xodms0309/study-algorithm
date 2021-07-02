function solution(p) {
    var answer = '';
    let u='';
    let v='';
    //u, v로 분리하는 과정
    const splitBrace=(p)=>{
        let right=0;
        let left=0;
        u='';
        while (true){        
            let popped=p[0];
            p=p.slice(1);
            u+=popped;
            if (popped==='(') left++;
            else if (popped===')') right++;
            if (left===right) break;
        }
        v=p;
    }
    //균형잡힌 괄호 문자열인지 판별
    const rightBrace=(p)=>{
        let stack=[];
        for (let i=0; i<p.length; i++){
            if (p[i]==="(") stack.push([i]);
            else if (p[i]===")") stack.pop();
        }
        if (stack.length===0) return true;
        else return false;
    }
    //4-4과정
    const reverseBracket=(p)=>{
        return p.slice(1).slice(0,-1).replace( /\(|\)/g , i=>i==="(" ? ")" : "(" );
    }
    const recursive=(p)=>{
        if (p.length===0) return p;
        splitBrace(p);
        if (rightBrace(u)){
             return u+recursive(v);
        }
        else{
            let reverse=reverseBracket(u);
            let temp="("+recursive(v)+")"+reverse;
            return temp;
        }
    }
    answer=recursive(p);
    return answer;
}
