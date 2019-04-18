#include <stdio.h>

int main (){
    int A,B,C,D,E,F,G,H;
    A=11*3%5;
    B=55%10;
    C=3*3+5*5;
    D=3*(3+5)*5;
    E=(3*3+5)-5;
    F=5*7-3;
    G=5*(7-3);
    H=15/3+7;

    printf("The value of A=11*3%5 is: %d", A);
    printf("\n\nThe value of B=55%10 is: %d", B);
    printf("\n\nThe value of C=3*3+5*5 is: %d", C);
    printf("\n\nThe value of D=3*(3+5)*5 is: %d", D);
    printf("\n\nThe value of E=(3*3+5)-5 is: %d", E);
    printf("\n\nThe value of F=5*7-3 is: %d", F);
    printf("\n\nThe value of G=5*(7-3) is: %d", G);
    printf("\n\nThe value of H=15/3+7 is: %d", H);

    getch();
    return 0;
}
