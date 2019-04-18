#include <stdio.h>

int main(){
    int a, b, total;

    printf("Enter first value: ");
    scanf("%i", &a);

    printf("\nEnter seond value: ");
    scanf("%i", &b);

    if(a % b == 0){
       printf("\n%i is evenly divisible by %i\n", a, b);
       total = a / b;
       printf("%i / %i = %i\n", a, b, total);
    }else{
       printf("\n%i is not evenly divisible by %i\n", a, b);
    }

    return 0;
}
