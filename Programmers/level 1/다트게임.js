function solution(dartResult) {
    var answer = 0;
    let arr=[0];
    let score=0;
    for (let i=0; i<dartResult.length; i++){
        //점수
        if (!isNaN(dartResult[i])){
            if (dartResult[i]==='1'&&dartResult[i+1]!='0') score=1;
            else if (dartResult[i]==='0'){
                if (dartResult[i-1]==='1') score=10;
                else score=0;
            }
            else score=parseInt(dartResult[i]);
        }
        //보너스+옵션
        if (dartResult[i]==='S'){
            if (dartResult[i+1]==='*'){
                arr.push(arr.pop()*2);
                arr.push(score*2);
            }
            else if (dartResult[i+1]==='#'){
                arr.push(score*(-1));
            }
            else arr.push(score);
        }
        else if (dartResult[i]==='D'){
            if (dartResult[i+1]==='*'){
                arr.push(arr.pop()*2);
                arr.push(Math.pow(score, 2)*2);
            }
            else if (dartResult[i+1]==='#'){
                arr.push(Math.pow(score,2)*(-1));
            }
            else arr.push(Math.pow(score,2))
        }
        else if (dartResult[i]==='T'){
            if (dartResult[i+1]==='*'){
                arr.push(arr.pop()*2);
                arr.push(Math.pow(score, 3)*2);
            }
            else if (dartResult[i+1]==='#'){
                arr.push(Math.pow(score,3)*(-1));
            }
            else arr.push(Math.pow(score,3));
        }
    }
    //점수 계산
    for (let i=0; i<arr.length; i++){
        answer+=arr[i];
    }
    return answer;
}
