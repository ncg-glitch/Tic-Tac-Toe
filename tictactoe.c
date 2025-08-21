#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<string.h>
#define k 1000

struct move{
  int row,col;
}move;

//draw checker
bool isFull(char board[][3]){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board[i][j]=='\0'){
                return false;
            }
        }
    }
  return true;
}

//heuristic function
int check(char board[][3],int depth){
    for(int i=0;i<3;i++){
    //row & column wise
    if((board[i][0]==board[i][1] && board[i][1]==board[i][2] && board[i][0]=='x')||(board[0][i]==board[1][i] && board[1][i]==board[2][i] && board[0][i]=='x')){
        return 10/depth;
      }
    if((board[i][0]==board[i][1] && board[i][1]==board[i][2] && board[i][0]=='o')||(board[0][i]==board[1][i] && board[1][i]==board[2][i] && board[0][i]=='o')){
        return -10/depth;
      }
    }
   //checking diagonals
    if((board[0][0]==board[1][1] && board[1][1]==board[2][2] && board[1][1]=='x')||(board[0][2]==board[1][1] && board[1][1]==board[2][0] && board[1][1]=='x')){
        return 10/depth;
      }
    if((board[0][0]==board[1][1] && board[1][1]==board[2][2] && board[1][1]=='o')||(board[0][2]==board[1][1] && board[1][1]==board[2][0] && board[1][1]=='o')){
        return -10/depth;
      }
  return 0;
}

//displays the game board
void grid(char board[][3]){
   for(int i=0;i<3;i++){
    printf("\t\t\t");
    for(int j=0;j<5;j++){
     if(j%2==0){
     char c=board[i][j/2];
        if(i!=2){
          if(c!='\0'){ 
            printf("_%c_",c);
          }
          else{ 
            printf("___"); 
        }
     }
        else{
          if(c!='\0'){ 
            printf(" %c ",c); 
          }
          else{ 
            printf("   ") ; 
          }
        }
    }
       else{
        printf("|");
       }
    }printf("\n");
  }printf("\n");
}

//validates and adds move to board
void input(char board[][3],char ch,char name[]){
    char n[100];
    int row,col;
    bool input=true;
  while(input){
    printf("%s's turn:",name);
    scanf("%s",&n);
    float num=atof(n);
    if(num && strlen(n)==1){
      float frac=num-floor(num);
      row=(num>3)?((num>6)?2:1):0;
      col=((int)num%3==0)?2:((int)num%3==2)?1:0;
      if(frac==0 && num>=1 && num<=9 && (board[row][col])?false:true){
        input=false;
      }
      else{
        printf("INVALID MOVE!!!\n");
      }
    }
    else{
      printf("INVALID MOVE!!!\n");
    }
 }
 board[row][col]=ch;
}

//minimax
int minimax(char board[][3],char c,int alpha,int beta,int depth){
  int res=check(board,depth);
  if(res!=0 || isFull(board)){
    return res;
  } 
  int bestscore=(c=='x')?-k:k;
    for(int i=0;i<3;i++){
      for(int j=0;j<3;j++){
        if(board[i][j]=='\0'){
           board[i][j]=c;
           int score=minimax(board,(c=='x')?'o':'x',alpha,beta,depth+1);
           board[i][j]='\0';
           bestscore=(c=='x')?((score>bestscore)?score:bestscore):((score<bestscore)?score:bestscore);
           (c=='x')?(alpha=(alpha>score)?alpha:score):(beta=(beta<score)?beta:score);
           if(alpha>=beta){
            goto end;
          }
        }
      }
    }
    end:
    return bestscore;
  }

//AI
void bestmove(char board[][3]){
  int bestscore=k;
   for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      if(board[i][j]=='\0'){
        board[i][j]='o';
        int score=minimax(board,'x',-k,k,1);
        board[i][j]='\0';
        if(score<bestscore){
          bestscore=score;
          move.row=i;
          move.col=j;
        }
      }
    }
  }
}

void main(){
  char player1[100],player2[100]="AI";
  char board[3][3]={};
  bool nxtrnd=true;
  char single[100],multi[100];
  srand(time(0));
  bool player=rand()%2;

  //rules of the game
  printf("============================================================================================Welcome To TIC-TAC-TOE==============================================================================================\n");
  printf("\nThe game will ask for the name(s) of the player(s) and the position of their next move.\n");
  printf("The position is an integer number between 1 and 9 (inclusive) which corresponds to any of the positions on the Tic-Tac-Toe grid as shown below:\n\n");
    char a[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
    grid(a);
  printf("The game has 2 modes Single player and Multi player. You can choose to play either one of them by pressing the \"y\" key otherwise press the \"n\" key.\n");
  printf("The player who goes first will be chosen at random.If you choose to play in Single player mode then you will be playing as \"x\" and the computer will play as \"o\".\n");
 
  //single player
  printf("\nSingle Player:y\\n?\n");
  again1:
  gets(single);
  if(strcmp(single,"y") && strcmp(single,"n")){
    printf("PLEASE ENTER \"y\" OR \"n\"!\n");
    goto again1;
  }
  if(!strcmp(single,"y")){
   printf("Enter name of player:");
   gets(player1);
   printf("\n");
   while(nxtrnd){
     player=(player)?false:true;
     if(player){
      input(board,'x',player1);
     }
     else{
     printf("My turn:\n");
     bestmove(board);
     board[move.row][move.col] = 'o';
     }
     grid(board);
     if(check(board,1)!=0 || isFull(board)){
       nxtrnd=false;
      }
    }
  }

  //multi player
  else{
  printf("Multi Player:y\\n?\n");
  again2:
  gets(multi);
  if(strcmp(multi,"n") && strcmp(multi,"y")){
    printf("PLEASE ENTER \"y\" OR \"n\"!\n");
    goto again2;
  }
  if(!strcmp(multi,"y")){
  printf("Enter name of player x:");
  gets(player1);
  printf("Enter name of player o:");
  gets(player2);
  printf("\n");
  while(nxtrnd){
  char p= (player)?'x':'o';
  input(board,p,(p=='x')?player1:player2);
  player=(player)?false:true;
  grid(board);
  if(check(board,1)!=0 || isFull(board)){
    nxtrnd=false;
    }
   }
  }
 }

//printing winner and loser or draw 
if(!strcmp(single,"y")||!strcmp(multi,"y")){
  if(check(board,1)!=0){
  char *a= check(board,1)>0?player1:player2;
  char *b= strcmp(a,player1)?player1:player2;
  printf("%s WINS!!! %s LOSES!!!",a,b);
  }
  else{
  printf("DRAW.");
  }
}
else{
  printf("Game Ended with no moves played.");
  }
}