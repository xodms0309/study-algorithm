function solution(skill, skill_trees) {
    var answer = 0;
    let temp=[];
    let str='';
    for (let i=0; i<skill_trees.length;i++){
        str=skill_trees[i].split("").filter(i=>skill.includes(i)).join("");
        if (str===skill.substring(0, str.length)) answer++;
    }
    return answer;
}
