#include <stdio.h>


    int main(){
        int array[100], i, n;

        printf("Enter the size of array: ");
        scanf("%d", &n);

        for(i = 0; i < n; i++){
           printf("Enter element %d: ", i + 1);
           scanf("%d", &array[i]);
        }

        printf("Even numbers in the array are: ");
        for(i = 0; i < n; i++){
            if(array[i] % 2 == 0){
                printf("%d ", array[i]);
       }
    }

       printf("\nOdd numbers in the array are: ");
       for(i = 0; i < n; i++){
            if(array[i] % 2 != 0){
                printf("%d ", array[i]);
       }
    }

   return 0;
}
