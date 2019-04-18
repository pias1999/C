#include <stdio.h>

int main(){
  	int num1, num2, digit = 0;
  	char minus = '-';

  	printf("Enter your number: ");
  	scanf ("%i", &num1);

  	if(num1 >= 0){
      do{
        digit = num1 % 10;
        printf ("%i", digit);
        num1 = num1 / 10;
    }
    while (num1 !=0);
      printf ("\n");
    }

    else{
      num2 = num1 * -1;
      do{
        digit = num2 % 10;
        printf ("%i", digit);
        num2 = num2 / 10;
      }

      while(num2 != 0);
      printf("%c", minus);
      printf("\n");
      }

    return 0;
}
