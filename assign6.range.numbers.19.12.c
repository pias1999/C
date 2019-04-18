#include <stdio.h>

int main(){
    int i, a;
    int num;
    int largest;
    int smallest;
    printf("Enter the size of Array: ");
    scanf("%d", &a);
    printf("Enter first number: ");
    scanf("%d", &num);
    largest = num;
    smallest = num;
    for(i=1; i<= a -1 ; i++){
        printf ("\nEnter another number: ");
        scanf ("%d", &num);
        if(num > largest){
        largest = num;
        }if(num < smallest){
        smallest = num;
        }
    }
    printf("\nThe largest number is: %d", largest);
    printf("\nThe smallest number is: %d", smallest);
    return 0;
}
