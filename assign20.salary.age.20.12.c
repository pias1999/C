#include <stdio.h>

int main(){
    char name[100];
    int age;
    int salary;

    printf("Enter your name: ");
    scanf("%s", &name);

    printf("\nPlease enter your age: ");
    scanf("%d", &age);

    printf("\nPlease enter your salary: ");
    scanf("%d", &salary);

    if(age > 30 && salary > 1000000){
        printf("You are successful!");
    }else{
        printf("Good luck with life ahead.");
    }

  return 0;
}
