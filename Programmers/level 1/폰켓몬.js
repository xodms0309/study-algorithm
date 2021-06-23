function solution(nums) {
    var answer = 0;
    let kinds=[];
    let cnt=1;
    nums.sort();
    for (let i=0; i<nums.length; i++){
        if (nums[i]===nums[i+1]) cnt++;
        else{
            kinds.push(cnt);
            cnt=1;
        }
    }
    if (kinds.length>=nums.length/2) return nums.length/2;
    else return kinds.length;

}
