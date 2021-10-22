function solution(m, n, board) {
    var answer = 0;
    board = board.map((block) => block.split(""));
    while (true){
        let blockArr=[];
        for (let i=0; i<m-1;i++){
            for (let j=0; j<n-1; j++){
                if (board[i][j]){
                    if (board[i][j]==board[i][j+1]&&
                        board[i][j]==board[i+1][j]&&
                        board[i][j]==board[i+1][j+1]){
                        blockArr.push([i,j]);
                    }
                }
            }
        }
        //loop 탈출 조건
        if (!blockArr.length) {
            answer=[].concat(...board).filter((block)=>block===0).length;
            break;
        }
        //블록 삭제
        for (let i=0; i<blockArr.length; i++){
            const col=blockArr[i][0];
            const row=blockArr[i][1];
            board[col][row]=0;
            board[col+1][row]=0;
            board[col][row+1]=0;
            board[col+1][row+1]=0;
        }
        //재정렬
        for (let i=m-1; i>=0; i--){
            for (let j=n-1; j>=0;j--){
                if (board[i][j]==0){
                    //현재 라인보다 위 블록
                    let index=i-1;
                    while (index>-1){
                        //위 블록이 빈 블록이 아닐 때
                        if (board[index][j]){
                            board[i][j]=board[index][j];
                            board[index][j]=0;
                            break;
                        }
                        index--;
                    }
                }
            }
        }
    }
    return answer;
}
