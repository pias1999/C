#include <stdio.h>
#define MAX 50

 int main(){
        int array[MAX], n, i, max1, max2, temp;

        printf("Enter the size of array: ");
        scanf("%d", &n);
        for(i = 0; i < n; i++){
           printf("Enter element %d: ", i + 1);
           scanf("%d", &array[i]);
        }

        max1 = array[0];
        max2 = array[1];

        if(max1 < max2){
            temp = max1;
            max1 = max2;
            max2 = temp;
        }

        for(i = 0; i < n; i++){
            if (array[i] >= max1){
                max2 = max1;
                max1 = array[i];
            }else if (array[i] > max2){
                max2 = array[i];
            }
        }

        printf("\nThe largest number is: %d", max1);
        printf("\nThe second largest number is: %d\n", max2);

        return 0;
   }
