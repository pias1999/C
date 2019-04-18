#include <stdio.h>

int main (){
    double a, b, total;

    printf("Enter first value: ");
    scanf("%lf", &a);

    printf("\nEnter second value: ");
    scanf("%lf", &b);

    total = a / b;

    if (b > 0){
       printf("\n%.2lf divided by %.2lf: %.3f\n", a, b, total);
    }else{
       printf("\nCannot divide by zero.\n");
    }

    return 0;
}
