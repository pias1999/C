#include <stdio.h>
#include <math.h>

int board[20], count, qn;

void print(int n){ //this function prints all the combinations of the queens
     int i, j;
     printf("\n\nSolution %d:\n\n",++count);
     printf("\n\n'Q' is the positions of queens ");
     printf("\n\n'x' is the blocked squares");
     printf("\n\n'-' is the empty squares\n\n");


     for(i = 1;i <= 8;++i)
      printf("\t%d", i);

     for(i = 1;i <= 8;++i){
      printf("\n\n%d",i);
      for(j = 1;j <= 8;j++){
       if(board[i] == j && j <= qn)
        printf("\tQ");
        else if(board[i] == j + 1) //searches for blocked squares
            printf("\tx");

     else
        printf("\t-");
      }
     }
    }
//funtion to check conflicts
int place(int row, int column){
     int i;
     for(i = 1;i <= row - 1;++i){
      //checking column and digonal conflicts
      if(board[i] == column)
       return 0;
      else
       if(abs(board[i] - column) == abs(i - row))
        return 0;
     }

     return 1;
}
//function to check the proper position of the queens
void queen(int row, int n){
     int column;
     for(column = 1;column <= 8;++column){ //number of columns in the chess board
      if(place(row, column)){
       board[row] = column;
       if(row == 8) //end of the chess board
        print(8);
       else
        queen(row + 1, 8);
      }
   }
}

int main(){
 int i, j;

 printf("\nEnter number of Queens:");
 scanf("%d", &qn);
 queen(1, qn);

 return 0;
}

