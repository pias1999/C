#include <stdio.h>

int main(){
    float accum = 0, number = 0;
    char oper;

      do{
         printf("\nPlease enter a number and an operator: ");
         scanf("%f %c", &number, &oper);
           if(number == 0 && oper == 'N'){
              printf ("Total = %f", accum);
              printf ("\nEnd of calculations.");
           }else if(oper == '+', '-', '*', '/', 'S'){
                   switch(oper){
                     case 'S':
                      accum = number;
                      printf("= %f", accum);
                      break;
                     case '+':
                      accum = accum + number;
                      printf("= %f", accum);
                      break;
                     case '-':
                      accum = accum - number;
                      printf("= %f", accum);
                      break;
                     case '*':
                      accum = accum * number;
                      printf("= %f", accum);
                      break;
                     case '/':
                       if( number != 0){
                         accum = accum / number;
                         printf("= %f", accum);
                       }else
                        printf("Cannot divide by zero.");
                        break;
                      default:
                       printf ("Error. Please ensure you enter a correct number and operator.");
                       break;
                    }
                  }
                else
                 printf("Error. Please ensure you enter a correct number and operator.");
         }while(oper != 'N');

          return 0;
}
