function solution(clothes) {
    var answer = 1;
    let clothesType=[];
    let map=new Map();
    //1. 옷의 종류만 담은 배열 만들기
    for (let i=0; i<clothes.length; i++){
        clothesType.push(clothes[i][1]);
    }
    //2. 종류 당 몇 벌이 있는지 체크
    clothesType.forEach(element=>{
            if (map.has(element)) map.set(element, map.get(element)+1);
            else map.set(element, 1);
    });
    //3. 서로 다른 옷의 조합의 수
    map.forEach(value=>{
        answer=answer*(value+1);
    })
    //4. 한 가지는 옷을 하나도 입지 않은 가짓수라서 빼줌
    return answer-1;
}
