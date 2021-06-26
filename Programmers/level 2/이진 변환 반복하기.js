function solution(s) {
    var answer = [];
    let cnt=0;
    let zero=0;
    const removeZero=(s)=>{
        return s.split("").filter(num=>num==='1');
    };
    const toBinary=(s)=>{
        let l= s.map(num=>parseInt(num)).join('').length;
        return l.toString(2);
    }
    while (s.length!=1){
        zero+=s.split("").filter(num=>num==='0').length;
        s=removeZero(s);
        s=toBinary(s);
        cnt++;
    }
    answer.push(cnt,zero)
    return answer;
}
