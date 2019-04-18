#include <stdio.h>

int main(){
    int r, c;
    int cross[5][5]={2,0,0,0,1,0,2,0,1,0,0,0,0,0,0,0,1,0,2,0,1,0,0,0,2};

    for (r = 0;r < 5;r++){
        for (c = 0;c < 5;c++){
            if (r == c || r + c == 4 || (r == 2 && c == 2)){
                printf("%d\t", cross[r][c]);
            } else {
                printf(" \t");
            }
            if (c == 4){
                printf("\n");
            }

        }
    }
    return 0;
}
