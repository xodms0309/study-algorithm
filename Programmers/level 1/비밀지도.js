function addZero(n, arr){
    for (let i=0; i<n; i++){
        let zero='';
        if (arr[i].length<n) {
            for (let j=0; j<n-(arr[i].length); j++)
                zero+='0';
            arr[i]=zero+arr[i];
        }
    }
}
function solution(n, arr1, arr2) {
    let answer = [];
    let arrToBinary=[];
    for (let i=0; i<n; i++){
        answer.push(arr1[i]|arr2[i]);
    }
    arrToBinary=answer.map(i=>i.toString(2));
    addZero(n, arrToBinary);
    for (let i=0; i<n;i++){
        arrToBinary[i]=arrToBinary[i].replace(/1/g, '#');
        arrToBinary[i]=arrToBinary[i].replace(/0/g, ' ');
    }
    return arrToBinary;
}
