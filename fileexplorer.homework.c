#include <stdio.h>

int main(){
    int i,j;
    int r,c,t;
    char a[5] = {'A','B','C','D','E'};
    printf("Here are all the letters:\n");
    for( i= 0; i < 5; i++){
        printf("%c\t", a[i]);
    }
    char b[5] = {'V', 'W', 'X', 'Y', 'Z'};

    t = a[r];
   a[r] = a[c];
   a[c] = t;
   for(j = 0; j < 5; j++){
        printf("\n%c\t", b[j]);
    }


return 0;
}
