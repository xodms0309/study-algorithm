function solution(progresses, speeds) {
    var answer = [];
    let workDay=[];
    let releaseDay=0;
    workDay=progresses.map((v,i)=>Math.ceil((100-v)/speeds[i])); //작업이 소요되는 날짜
    //console.log(workDay)
    for (let i=0; i<workDay.length; i++){
        if (releaseDay<workDay[i]){
            answer.push(1);
            releaseDay=workDay[i]; 
        } //배포 날에 준비가 되지 않은 경우
        else{
            answer[answer.length-1]++; //배포 날에 준비가 된 경우
        }
    }
    return answer;
}
