#include <stdio.h>

int main(){
    int ar[1000];
    int i, n;
    int sum = 0;

    printf("Enter the array size: ");
    scanf("%d", &n);

    printf("Enter %d values in the array: ", n);
    for(i = 0; i < n; i++){
        printf("\nEnter value %d: ", i+1);
        scanf("%d", &ar[i]);
    }

    for(i = 0; i < n; i++){
        sum += ar[i];
    }

    printf("Sum of all values of the array is = %d", sum);

    return 0;
}
