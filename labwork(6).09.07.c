#include <stdio.h>

int main(){

    int num1 = 0, digit = 0, num2 = 0, mult = 1;

    printf("This program will convert numbers as numerals into words.\n\n");
    printf("Enter a Number: ");
    scanf("%i", &num1);

  while(num1 != 0){
        digit = num1 % 10;
        num1 = num1 / 10;
        num2 = num2 * mult + digit;
        while(mult != 10){
              mult = mult * 10;
        }
  }
        digit
        = 0;

        do{
        digit = num2 % 10;
        if(digit == 0){
               printf("zero ");
           }else if(digit == 1){
               printf("one ");
           }else if(digit == 2){
               printf("two ");
           }else if(digit == 3){
               printf("three ");
           }else if(digit == 4){
               printf("four ");
           }else if(digit == 5){
               printf ("five ");
           }else if(digit == 6){
               printf("six ");
           }else if(digit == 7){
               printf("seven ");
           }else if(digit == 8){
               printf("eight ");
           }else
               printf("nine ");
               num2 = num2 / 10;
           }while (num2 != 0);


    return 0;
}
