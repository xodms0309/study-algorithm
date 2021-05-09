function solution(participant, completion) {
    let answer = '';
    let result=participant.reduce((allNames, name)=>{
        if (name in allNames) allNames[name]++;
        else allNames[name]=1;
        return allNames;
    }, {});
    completion.forEach(element=>{
        result[element]--;
    });
    for (let i in result){
        if (result[i]) answer=i;
    }
    return answer;
}
