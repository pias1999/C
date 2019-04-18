#include <stdio.h>
#include <limits.h>

int main(){
    int ar[1000];
    int length;
    int i;
    int max1, max2;

    printf("Enter the length of the array: ");
    scanf("%d", &length);

    for(i = 0;i < length;i++){
        printf("Enter element %d: ", i+1);
        scanf("%d", &ar[i]);
    }

    max1 = max2 = INT_MIN;

    for(i =  0;i < length;i++){
        if(ar[i] > max1){
            max2 = max1;
            max1 = ar[i];
        }else if(ar[i] > max2 && ar[i] != max1){
            max2 = ar[i];
        }
      }
        if(max2 == INT_MIN){
            printf("There is no second largest element.");
        }else{
            printf("The second largest element is: %d", max2);
        }

    return 0;
}
