#include <stdio.h>

int main(){
    int ar[1000];
    int i;
    int max, min;
    int length;

    printf("Enter the length of the array: ");
    scanf("%d", &length);


    for(i = 0;i < length;i++){
        printf("Enter element %d: ", i+1);
        scanf("%d", &ar[i]);
    }

    max = ar[0];
    min = ar[0];

    for(i = 1;i < length;i++){

        if(ar[i] > max){
            max = ar[i];
        }
        if(ar[i] < min){
            min = ar[i];
        }
    }

    printf("Maximum element in the array is = %d.\n", max);
    printf("Minimum element in the array is = %d.", min);

    return 0;
}
