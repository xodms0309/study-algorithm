function solution(s) {
    var answer = true;
    if (s.length!==4&&s.length!==6) answer=false; //길이 체크
    s=s.split('').map(i=>parseInt(i)); //문자열을 한자리씩 나눠 배열로 만든 뒤 숫자로 변환
    for (let i=0; i<s.length; i++){
        if (isNaN(s[i])) answer=false;  //문자가 포함되어있다면 NaN일테니 체크
    }
    return answer;
}
