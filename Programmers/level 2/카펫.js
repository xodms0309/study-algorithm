function solution(brown, yellow) {
    var answer = [];
    let wyellow=0;
    let hyellow=0;
    for (let i=yellow; i>=1; i--){
        if (yellow%i===0) {
            wyellow=i;
            hyellow=yellow/i;
            if (2*hyellow+2*wyellow+4===brown) {
                answer.push(wyellow+2, hyellow+2);
                break;
            }
        }
    }
    return answer;
}
