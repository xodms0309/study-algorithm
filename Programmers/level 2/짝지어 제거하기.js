function solution(s){
    let temp=[];
    if (s.length%2!==0) return 0;
    for (let i=0; i<s.length;i++){
        if (s[i]===temp[temp.length-1]) {
            temp.pop();
            continue;
        }
        temp.push(s[i]);
    }
    if (temp.length===0) return 1;
    else return 0;
}
