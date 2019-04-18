#include <stdio.h>

void swap(){
   int num1, num2;
   int t;

   printf("Enter first number: ");
   scanf("%d", &num1);
   printf("Enter second number: ");
   scanf("%d", &num2);

   printf("\nBefore Swapping:");
   printf("\nFirst Number = %d\nSecond Number = %d\n", num1, num2);

   t = num1;
   num1 = num2;
   num2 = t;

   printf("\nAfter Swapping:");
   printf("\nFirst Number = %d\nSecond Number = %d\n",num1 ,num2);
}
int main(){
    swap();
    return 0;
}
