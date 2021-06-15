function solution(bridge_length, weight, truck_weights) {
    let pastBridge=[];
    let onBridge=[];
    let sumWeight=0;
    let time=0;
    let truck=truck_weights.length; //트럭의 개수
    for (let i=0; i<bridge_length;i++){
        onBridge.push(0); //큐 구현을 위해 0으로 채워 넣는다.
    }
    while (pastBridge.length!=truck){
        let dequeItem=onBridge.shift(); //1초마다 다리의 한 칸씩 움직임 구현
        let nextTruck=truck_weights.shift();
        
        sumWeight=sumWeight+nextTruck-dequeItem; 
        
        if (dequeItem!==0) pastBridge.push(nextTruck); //만약 트럭이 다리 끝에 있다면 pastBridge로 이동
        
        if (onBridge.filter(i=>i!=0).length<bridge_length&&sumWeight<=weight){ //트럭이 더 올라갈 수 있을 때
            onBridge.push(nextTruck);
         }
         else{ //더 못 올라가는 경우
             truck_weights.unshift(nextTruck); //다시 대기 트럭으로 이동
             sumWeight-=nextTruck;
             onBridge.push(0); //트럭 대신 빈 자리 삽입
         }
        time++;
    }

    return time;
}
