#include <stdio.h>

void element(){
    int i, a;
    double ar[1000];

    printf("Enter total number of elements: ");
    scanf("%d", &a);

    for(i = 0; i < a; i++){
       printf("\nEnter Element %d: ", i+1);
       scanf("%lf", &ar[i]);
    }

    for(i = 1; i < a; i++){
       if(ar[0] < ar[i]){
           ar[0] = ar[i];
       }
    }
    printf("The Largest element is = %.2lf", ar[0]);
}
int main(){
    element();
    return 0;
}
