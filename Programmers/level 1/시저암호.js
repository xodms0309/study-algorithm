function solution(s, n) {
    var answer = '';
    let splitStr=s.split("");
    for (let i=0; i<splitStr.length; i++){
        let toAscii=splitStr[i].charCodeAt();
        //대문자
        if (toAscii>=65&&toAscii<91){
            if(toAscii+n>90) splitStr[i]=String.fromCharCode(toAscii-26+n);
            else splitStr[i]=String.fromCharCode(toAscii+n);
            
        }
        if (toAscii>=97&&toAscii<123){
            if (toAscii+n>122) splitStr[i]=String.fromCharCode(toAscii-26+n);
            else splitStr[i]=String.fromCharCode(toAscii+n);
        }
    }
    answer=splitStr.join("");
    return answer;
}
