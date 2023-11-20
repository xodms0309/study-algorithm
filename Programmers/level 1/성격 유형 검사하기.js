function solution(survey, choices) {
    var answer = '';
    let categories={R:0, T:0, C:0, F:0, J:0, M:0, A:0, N:0};
    
    for (let i=0; i<survey.length; i++) {
        const first = survey[i][0];
        const second = survey[i][1];
        if (choices[i]===4) continue;
        //비동의
        if (choices[i]<4) {
            categories[first]+=(4-choices[i]);
        }
        //동의
        else {
            categories[second]+=(choices[i]-4);
        }
    }
    answer+=categories['R'] >= categories['T'] ? 'R' : 'T';
    answer+=categories['C'] >= categories['F'] ? 'C' : 'F';
    answer+=categories['J'] >= categories['M'] ? 'J' : 'M';
    answer+=categories['A'] >= categories['N'] ? 'A' : 'N';
    
    return answer;
}
