function solution(record) {
    var answer = [];
    let recordObj={};
    for (let i=0; i<record.length; i++){
        if (record[i].split(" ")[0]==="Enter"||record[i].split(" ")[0]==="Change") {
            recordObj[record[i].split(" ")[1]]=record[i].split(" ")[2];
        }
    }
    for (let i=0; i<record.length; i++){
        if (record[i].split(" ")[0]==="Enter") {
            answer.push(recordObj[record[i].split(" ")[1]]+"님이 들어왔습니다.");
        }
        else if (record[i].split(" ")[0]==="Leave"){
            answer.push(recordObj[record[i].split(" ")[1]]+"님이 나갔습니다.");
        }
    }
    return answer;
}
