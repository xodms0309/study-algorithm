function solution(begin, target, words) {
    var answer = 0;
    const wlength=words.length;
    let visited=Array.from(wlength).fill(0);
    if (!words.includes(target)) return 0;
    const search=(begin, words, depth)=>{
        if (begin===target){
            answer=depth;
            return answer;
        }
        else{
            for (let i=0; i<words.length; i++){
                let cnt=0;
                if (visited[i]) continue;
                for (let j=0; j<begin.length; j++){
                    if (words[i][j]===begin[j]) cnt++;
                }
                if (cnt===begin.length-1) {
                    visited[i]=1;
                    search(words[i], words, depth+1);
                    visited[i]=0;
                }
            }
        }
    }
    search(begin, words, 0);
    return answer;
}
