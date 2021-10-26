function solution(msg) {
    var answer = [];
    let dictionary={};
    for (let i=1; i<=26; i++){
        dictionary[String.fromCharCode([i+64])]=i;
    }
    const msgArray=msg.split("");
    let temp=[];
    let i=0;
    while (true){
        let word=msgArray[i];            
        while (msgArray[i]){
            //현재 단어가 존재한다면
            if (dictionary[word]){
                i++; 
                let candidate=word;
                word+=msgArray[i];
                if (!dictionary[word]) answer.push(dictionary[candidate]);
            }
            else{
                dictionary[word]=Object.keys(dictionary).length+1;
                break;
            }            
        }
        if (i>=msgArray.length) break;
    }
    return answer;
}
