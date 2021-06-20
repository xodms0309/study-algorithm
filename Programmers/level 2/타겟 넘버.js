function solution(numbers, target) {
    let answer=0;
    const l=numbers.length;
    const dfs=(depth, numbers, result)=>{
        if (depth===l) {
            if (result===target) answer++;
        }
        else{
                dfs(depth+1, numbers.slice(1), result+numbers[0]);
                dfs(depth+1, numbers.slice(1), result-numbers[0]);
        }
    }
    dfs(0, numbers, 0);
    return answer;
}
