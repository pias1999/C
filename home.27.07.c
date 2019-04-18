#include <stdio.h>

int main(void){
    //variable
    char str[100];

    int r,c,q;
    int id;
    int pass;

    printf("User ID: ");
    scanf("%d", &id);
    printf("Password: ");
    scanf("%d", &pass);
    int i = 172014012;
    int p = 654321;

    if(id == i && pass == p){

    printf("\n\n\t\t\t\tLOADING\n\t\t\t ");
        for(r=1;r<=20;r++){
            for(q=0;q<=100000000;q++);//to display the loading dot slowly
                printf(".");
            }

    printf("\nEnter a string: ");
    scanf("%s", str);

    int i;

      //output
    i = 0;
    while(str[i] != '\0'){
        printf("%c\n", str[i]);
        i++;
      }

   printf("End of code\n");
    }else{
        printf("EROOR");
    }

   return 0;
}
