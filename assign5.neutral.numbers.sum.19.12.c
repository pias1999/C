#include <stdio.h>

int main(){
    int i;
    int num;
    int sum = 0;

    printf("Enter a Number: ");
    scanf("%d",&num);

    for(i = 1; i <= num; ++i){

        sum += i;
    }
    printf("Sum of the number is = %d",sum);

    return 0;
}
