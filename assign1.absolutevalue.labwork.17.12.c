#include <stdio.h>
#include <conio.h>

int main(){
    int num;

    printf("Please enter a value: ");
    scanf("\n %d",&num);
    if(num < 0){
    num = (-1) * num;
    printf("\n Absolute value of the number is : %d",num);
   }
  return 0;
}
