function solution(jobs) {
    var answer = 0;
    const queue=[];
    jobs.sort((a,b)=>a[0]-b[0]);
    let current=0;
    let index=0;
    while (index<jobs.length||queue.length){
        if (index<jobs.length&&current>=jobs[index][0]){
            queue.push(jobs[index++]);
            queue.sort((a,b)=>a[1]-b[1]);
            continue;
        }
        if (queue.length){
            let [start, end]=queue.shift();
            current+=end;
            answer+=current-start;
        }
        else{
            current=jobs[index][0];
        }
    }
    return Math.floor(answer / jobs.length);
}
