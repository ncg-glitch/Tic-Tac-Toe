//heuristic function (version_1)
int check(char board[][3]){
    for(int i=0;i<3;i++){
    //row & column wise
    if((board[i][0]==board[i][1] && board[i][1]==board[i][2] && board[i][0]=='x')||(board[0][i]==board[1][i] && board[1][i]==board[2][i] && board[0][i]=='x')){
        return 10;
      }
    if((board[i][0]==board[i][1] && board[i][1]==board[i][2] && board[i][0]=='o')||(board[0][i]==board[1][i] && board[1][i]==board[2][i] && board[0][i]=='o')){
        return -10;
      }
    }
   //checking diagonals
    if((board[0][0]==board[1][1] && board[1][1]==board[2][2] && board[1][1]=='x')||(board[0][2]==board[1][1] && board[1][1]==board[2][0] && board[1][1]=='x')){
        return 10;
      }
    if((board[0][0]==board[1][1] && board[1][1]==board[2][2] && board[1][1]=='o')||(board[0][2]==board[1][1] && board[1][1]==board[2][0] && board[1][1]=='o')){
        return -10;
      }
  return 0;
}


