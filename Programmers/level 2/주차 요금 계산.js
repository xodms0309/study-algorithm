function solution(fees, records) {
    var answer = [];
    //요금 정의
    const defaultTime=fees[0];
    const defaultFees=fees[1];
    const perTime=fees[2];
    const perFees=fees[3];
    
    //시간 계산
    const changeTime=(time)=>{
        const newTime=time.split(':');
        const hour=parseInt(newTime[0]);
        const minute=parseInt(newTime[1]);
        return [hour, minute];
    }
    
    const calculateTime=(inTime, outTime)=>{
        let hour=outTime[0]-inTime[0];
        let minute=outTime[1]-inTime[1];
        if (outTime[1]<inTime[1]){
            hour-=1;
            minute+=60;
        }
        return (60*hour+minute);
    }
    
    //요금 계산
    const calculateFees=(totalTime)=>{
        if (totalTime>defaultTime) {
         return(Math.ceil((totalTime-defaultTime)/perTime)*perFees+defaultFees)   
        }
        else return defaultFees;
    }
    
    let parkinglot=[];
    
    records.map((record)=>{
        const newRecord=record.split(" ");
        const time=newRecord[0];
        const carNum=newRecord[1];
        const comment=newRecord[2];
        let parkedTime=0;
        let fees=0;
        const car=parkinglot.find((car)=>car.carNum===carNum);

        if(comment==="IN"){
            if (car===undefined){
               parkinglot.push({
                carNum:carNum,
                inTime: time,
                totalTime:0,
                }) 
            }
            else{
                car.inTime=time;
            }
        }
        else if (comment==="OUT"){
            const inTime=changeTime(car.inTime);
            const outTime=changeTime(time);
            parkedTime=calculateTime(inTime, outTime);
            car.inTime='';
            car.totalTime+=parkedTime;
        }
    })
    parkinglot.map((car)=>{
        if (car.inTime!==''){
            const parkedTime=calculateTime(changeTime(car.inTime), [23,59]);
            car.inTime='';
            car.totalTime+=parkedTime;
        }
    })
    parkinglot.sort((a,b)=>{return a.carNum-b.carNum}).map((car)=>{
        answer.push(calculateFees(car.totalTime))
    })
    return answer;
}
