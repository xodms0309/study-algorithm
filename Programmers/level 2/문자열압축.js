function solution(s) {
    let answer = s;
    const slen=s.length;
    //최대 압축할 수 있는 길이는 s의 길이의 절반
    //i개 단위로 압축
    for (let i=1; i<=slen/2; i++){
        let cnt=1;
        let temp="";
        for (let j=0; j<slen; j+=i){
            //앞 뒤 단위로 자른 문자열 비교
            let current=s.substring(j, j+i);
            let next=s.substring(j+i, j+i+i);
            if (current===next) cnt++;
            else {
                if (cnt>1) temp=temp+cnt+current;
                else {
                    temp+=current;
                }
                cnt=1;
            }
        }
        if (answer.length>temp.length) answer=temp;
    }
    return answer.length;
}
