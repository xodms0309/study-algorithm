function solution(board, moves) {
    let answer = 0;
    let stack=[];
    for(let i=0; i<moves.length; i++){
        let move=moves[i]-1;
        for (let j=0; j<board.length; j++){
            if (board[j][move]!=0) {
                stack.push(board[j][move]);
                board[j][move]=0;
                break;
            }
        }
        if (stack.length>=2&&(stack[stack.length-1]===stack[stack.length-2])){
                stack.pop();
                stack.pop();
                answer+=2;
        }
    }
    return answer;
}
