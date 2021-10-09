function solution(cacheSize, cities) {
    var answer = 0;
    let cache=[];
    //대소문자 구분 x
    cities=cities.map(city=>city.toLowerCase());
    for (let i=0; i<cities.length; i++){
        let index=cache.indexOf(cities[i]);
        //cache에 존재하지 않을 때
        if (index===-1){
            answer+=5;
            cache.push(cities[i]);
            //cacheSize보다 더 커지면 LRU알고리즘 실행
            if (cacheSize<cache.length){
                cache.shift();
            }
        }
        else{
            answer+=1;
            cache.splice(index, 1);
            cache.push(cities[i]);
        }
    }
    return answer;
}
