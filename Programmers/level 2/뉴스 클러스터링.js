function solution(str1, str2) {
    var answer = 0;
    let alphabet=/[^a-zA-Z]/;
    //1. 두 글자씩 끊기
    const splitStr=(strArr)=>{
        return strArr.split("").map((str, i)=>{
            return strArr.slice(i,i+2);
        })
    }
    let splitStr1=splitStr(str1);
    let splitStr2=splitStr(str2);
    
    //2. 특수문자가 포함된 원소 버리기
    //3. 대문자->소문자
    const removeSpecialChar=(strArr)=>{
        for (let i=0; i<strArr.length; i++){
            strArr[i]=strArr[i].replace(alphabet, '').toLowerCase();
        }
    }
    removeSpecialChar(splitStr1);
    removeSpecialChar(splitStr2);
    
    //3-1. 2글자가 아닌 원소 버리기
    splitStr1=splitStr1.filter(i=>i.length===2);
    splitStr2=splitStr2.filter(i=>i.length===2);

    //4. 교집합 구하기
    let intersection = 0;
    let str1Copy = splitStr1.slice();
    let str2Copy = splitStr2.slice();
    for (let i = 0; i < str1Copy.length; i++){
        if (str2Copy.indexOf(str1Copy[i]) !== -1){
            str2Copy.splice(str2Copy.indexOf(str1Copy[i]), 1);
            intersection++;
        }
    }
    
    //5. 합집합 구하기
    //합집합의 크기=str1크기+str2크기-교집합 크기
    let union=splitStr1.length+splitStr2.length-intersection;
    
    //정답구하기
    if (union===0) answer=1;
    else answer=intersection/union;
    return Math.floor(answer*65536);
}
