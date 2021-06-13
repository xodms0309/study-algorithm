function solution(arr1, arr2) {
    var answer = [];
    let list=[];
    for (let i=0; i<arr1.length; i++){
        list=[];
        for (let j=0; j<arr1[i].length; j++){
            list.push(arr1[i][j]+arr2[i][j]);
        }
        answer.push(list);
    }
    return answer;
}
