function solution(n, words) {
    var answer = [];
    let wordArray=[]; //나온 단어 저장
    let lastWord=""; //이전 단어의 마지막 글자
    let gameEnd=false;
    for (let i=0; i<words.length; i++){
        //번호
        let num=(i+1)%n;
        if (num===0) num=n;
        //차례
        let order=parseInt(i/n)+1;
        
        /* 이미 존재하는 단어를 말했을 때*/
        if (wordArray.includes(words[i])) {
            answer.push(num); //번호
            answer.push(order); //차례
            gameEnd=true;
        }
        
        /*이전 단어의 마지막 글자와 매치 되지 않을 때*/
        else if (i>0&&lastWord!==words[i][0]){
             answer.push(num); //번호
             answer.push(order); //차례
             gameEnd=true;
         }
        
        if (gameEnd) break;
        /*게임이 끝나지 않았을 때*/
        lastWord=words[i][words[i].length-1];
        wordArray.push(words[i]);
        
    }
    //탈락자가 없을 때
    if (gameEnd===false) {
        answer.push(0,0);
    }
    return answer;
}
