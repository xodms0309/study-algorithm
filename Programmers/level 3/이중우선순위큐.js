function solution(operations) {
    var answer = [];
    let que=[];
    operations.forEach((operation)=>{
        const opArray=operation.split(" ");
        if (opArray[0]==='I') {
            que.push(parseInt(opArray[1]));
        }
        else{
            if (que.length){
                //최댓값 삭제
                if (opArray[1]==="1") {
                    que.sort((a,b)=>a-b);
                    que.pop();
                }
                //최소값 삭제
                else {
                    que.sort((a,b)=>a-b).reverse();
                    que.pop();
                }
            }
        }
    })
    if (que.length) {
        que.sort((a,b)=>a-b);
        answer.push(que[que.length-1],que[0]);
    }
    else{
        answer.push(0,0)
    }
    return answer;
}
