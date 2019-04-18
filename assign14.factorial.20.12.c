#include <stdio.h>

double factorial(){
    int i;
    int num, fact = 1;

    printf("Enter a Number: ");
    scanf("%d",&num);

    for(i = 1; i <= num; i++){
        fact = fact * i;
        }
        printf("Factorial of %d is: %d", num, fact);

    return 0;
}
int main(){
    double ans = factorial();
    return 0;
}
