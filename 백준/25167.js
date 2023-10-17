const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');

const [n, m, p] = input[0].split(" ").map(Number);

const names = input[1].split(" ");
const infos = input.slice(2, 2+p).map((e)=>e.split(' '));

const problemStatus = Array.from({ length: n }, () => []);

const MAX_TIME = (24-10)*60;

for (let i=0; i<n; i++) {
    for (let j=0; j<m; j++) {
        problemStatus[i].push({name: names[j], startTime: 0, tryTime:0, solveTime: MAX_TIME});
    }
}

const calculateTime=(solveTime)=>{
    const [hour, min] = solveTime.split(":").map(Number);
    return hour*60 + min;
}

infos.forEach((info)=>{
    const [problemNumber, solveTime, name, status] = info;
    const target = problemStatus[Number(problemNumber)-1].find((element)=>element.name===name);
    
    //이미 맞힌 문제면 기록 x
    if (target.solveTime < MAX_TIME) return;
    
     if (target.tryTime===0) {
        target.startTime = calculateTime(solveTime);
    }
    
    //틀렸을 때
    if (status==='wrong') {
        target.tryTime+=1;
    }
    //맞았을 때
    else {
        target.tryTime+=1;
        target.solveTime=calculateTime(solveTime) - target.startTime;
    }
})

for (let i=0; i<n; i++) {
   problemStatus[i].sort((a, b)=> {
       if (a.solveTime === b.solveTime) {
            if (a.name < b.name) return -1;
            if (a.name > b.name) return 1;
            return 0;
       }
       return a.solveTime - b.solveTime;
   })
}

const result = [];

for (let i=0; i<m; i++) {
    result.push({name: names[i], score:0});
}

for (let i=0; i<n; i++) {
    let rank=1;
    
    problemStatus[i].forEach((status)=> {
        const target = result.find((element)=>element.name===status.name);
        
        //처음에 풀어서 정답인 경우 무효
        if (status.tryTime===1 && status.solveTime!==MAX_TIME) {
            target.score+=(m+1);
            return;
        }
        
        //기록이 없는 경우 무효
        if (status.tryTime===0) {
            target.score+=(m+1);
            return;
        }
        
        //기록이 있지만 틀린 경우
        if (status.tryTime>=1 && status.solveTime===MAX_TIME) {
            target.score+=m;
            return;
        }
        
        target.score+=rank;
        rank++;
    })
}

result.sort((a,b)=>{
    if (a.score===b.score) {
        if (a.name < b.name) return -1;
        if (a.name > b.name) return 1;
        return 0;
    }
    return a.score-b.score;
})

result.map(({name, score})=>console.log(name))

