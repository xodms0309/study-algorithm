function solution(bridge_length, weight, truck_weights) {
    let pastBridge=[];
    let onBridge=[];
    let totalWeight=0;
    let time=0;
    let truck=truck_weights.length; //트럭의 개수
    
    for (let i=0; i<bridge_length;i++){
        onBridge.push(0); //큐 구현을 위해 0으로 채워 넣는다.
    }
    
    while (pastBridge.length!=truck){
        let dequeItem=onBridge.shift(); //1초마다 다리의 한 칸씩 움직임
        let currentTruck=truck_weights[0];
        if (dequeItem!==0) pastBridge.push(dequeItem); //만약 트럭이 다리 끝에 있다면 pastBridge로 이동
        totalWeight=totalWeight-dequeItem; 
        if (totalWeight+currentTruck<=weight){ //트럭이 더 올라갈 수 있을 때
            onBridge.push(currentTruck);
            totalWeight+=currentTruck;
            truck_weights.shift();
         }
         else{ //더 못 올라가는 경우
             onBridge.push(0); //트럭 대신 빈 자리 삽입
         }
        time++;
    }
    return time;
}
