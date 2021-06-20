function solution(nums) {
    var answer = [];
    const isPrime=(n)=>{
        for (let i=2; i<n; i++){
            if (n%i===0) return false;
        }
        return true;
    }
    const dfs=(depth, nums, sum)=>{
        if (depth===3) answer.push(sum);
        else{
            for (let i=0; i<nums.length;i++){
                dfs(depth+1, nums.slice(i+1), sum+nums[i]);
            }
        }
    }
    dfs(0, nums, 0);
    answer=answer.filter(i=>isPrime(i));
    return answer.length;
}
