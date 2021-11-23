function solution(citations) {
    var answer = 0;
    citations.sort((a,b)=>a-b); //[0,1,3,5,6]
    const n=citations.length;
    for (let i=0; i<n;i++){
        let cnt=0;
        for (let j=i; j<n;j++){
            if (citations[i]<=citations[j]) 
                cnt++;
        }
        if (cnt>citations[i]) 
            cnt=citations[i];
        if (cnt>answer) 
            answer=cnt;
    }
    return answer;
}
