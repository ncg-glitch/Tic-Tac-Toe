#include<stdio.h>
#include<stdbool.h>

char board[3][3]={{'\0','o','\0'},
                  {'x','\0','o'},
                  {'x','x','x'}};
                  
void grid(){
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
  }
}

void main(){
   grid();
}