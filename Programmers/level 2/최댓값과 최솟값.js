function solution(s) {
    var answer = '';
    s=s.split(" ").map(i=>parseInt(i)); //공백을 기준으로 나눈 뒤 number 형식으로 바꿈
    return Math.min.apply(null, s).toString()+" "+Math.max.apply(null, s).toString();
}
