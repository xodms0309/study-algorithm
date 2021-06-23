function solution(n, t, m, p) {
    var answer = '';    
    let numArr=[];
    for (let i=0; i<t*m; i++){
        numArr.push(i.toString(n));
    }
    numArr=numArr.join('').split('');
    for (let i=0; i<t; i++){
        answer+=numArr[i*m+p-1];
    }
    return answer.toUpperCase();
}
