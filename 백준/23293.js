const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');

const [t, n] = input[0].split(" ").map(Number);
const logs = input.splice(1, 1+t).map((e)=>e.split(' '));

const players = Array.from({ length: n + 1 }).map(() => (
  {currentLocation: 1, items:{}})
);


const blockLogs=[];
const blockPlayers=[];

const hasItem=(items, targetItem)=>{
    if (!items[targetItem]) return false;
    if (items[targetItem]===0) return false;
    return true;
}


for (let i=0; i<t; i++) {
    const logId = Number(logs[i][0]);
    const playerId = Number(logs[i][1]);
    const code = logs[i][2];
    
    const target = players[playerId];

    switch(code) {
        //이동
        case 'M':
            const newLocation = Number(logs[i][3]);
            target.currentLocation = newLocation;
            break;
        //파밍
        case 'F':
            const item = Number(logs[i][3]);
            //플레이어가 현재 위치한 지역에서 얻을 수 없는 소재 아이템을 획득한 경우
            if (item!==target.currentLocation) {
                blockLogs.push(logId);
            }
            
            //부정행위로 획득한 아이템도 인정
            target.items[item]=target.items[item] ? target.items[item]+1: 1;
            
            break;
        //조합
        case 'C':
            const itemA = Number(logs[i][3]);
            const itemB = Number(logs[i][4]);
            
            
            //플레이어가 가지고 있지 않은 소재 아이템을 사용해 조합하는 경우
            if (!hasItem(target.items, itemA) || !hasItem(target.items, itemB)) {
                blockLogs.push(logId);
            }
            
            //부정행위로 조합 시 가지고 있는 소재 아이템만이 사용
            if (hasItem(target.items, itemA)) target.items[itemA]-=1;
            if (hasItem(target.items, itemB)) target.items[itemB]-=1;
            
            break;
        //공격
        case 'A':
            const attackPlayerId = Number(logs[i][3]);
            //플레이어가 다른 지역에 있는 상대 플레이어를 공격하는 경우

            const attackPlayer = players[attackPlayerId];
            
            if (attackPlayer.currentLocation !==target.currentLocation) {
                blockLogs.push(logId);
                blockPlayers.push(playerId);
            }
            
            break;
    }
}


const blockPlayerSet = new Set(blockPlayers)

console.log(blockLogs.length);
if (blockLogs.length) console.log(blockLogs.sort((a,b)=>{
  if(a > b) return 1;
  if(a < b) return -1;
  return 0;
}).join(" "));
console.log(blockPlayerSet.size);
if (blockPlayerSet.size) console.log([...blockPlayerSet].sort((a, b)=>{
  if(a > b) return 1;
  if(a < b) return -1;
  return 0;
}).join(" "));
