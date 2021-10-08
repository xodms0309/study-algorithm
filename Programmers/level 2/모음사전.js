function solution(word) {
    var answer = 0;
    const alphabet={'E':1, 'I':2, 'O':3, 'U':4};
    for (let i=0; i<word.length; i++){
        if (word[i]==='A') answer+=1;
        else{
            for (let j=4; j>i; j--){
            answer+=(5**(j-i))*alphabet[word[i]];
          }
            answer+=alphabet[word[i]]+1;
        }
    }
    return answer;
}
