function solution(s) {
    var answer = '';
    answer=s.toLowerCase().split(" "). //모든 문자를 소문자로 만들고, 공백을 기준으로 자름
    map(i=> {
        let a=i.split(""); //잘린 문자열에 대해 한 글자씩 자름
        if (a[0]!==undefined) a[0]=a[0].toUpperCase(); //공백인 경우제외하고 첫 글자를 대문자로
        return a.join(''); 
    }).join(' '); //다시 이어붙임
    return answer;
}
