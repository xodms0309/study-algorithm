function solution(id_list, report, k) {
    const answer = Array.from({length: id_list.length}, () => 0);
    const reportObj = id_list.reduce((acc,cur)=> (acc[cur]=[],acc),{});
    const reportSet=[...new Set(report)]; //중복 제거
    
    //신고당한 사람:[신고한 사람]
    reportSet.map((element)=>{
        element=element.split(' ');
        const user=element[0];
        const reported=element[1];
        reportObj[reported].push(user);
    })
    
    for (user in reportObj){
        if (reportObj[user].length>=k) {
            reportObj[user].forEach((report)=>{
                const id=id_list.indexOf(report);
                answer[id]++;
            })
        }
    }
    return answer;
}
