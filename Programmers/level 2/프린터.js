function solution(priorities, location) {
    let stack=[];
    while (location!=-1){
        let max=Math.max.apply(null, priorities); //현재 대기 목록의 최고 중요도 문서를 max로 정의
        if (priorities[0]!==max){
            priorities.push(priorities.shift()); //현재 문서를 맨 뒤로 이동
            if (location===0) location=priorities.length-1; //대기 목록 첫 번째 문서가 location의 문서였을 때
            else location--;
        }
        else{
            stack.push(priorities.shift());
            location--;
        }
    }
    return stack.length;
}
