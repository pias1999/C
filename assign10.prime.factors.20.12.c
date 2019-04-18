#include <stdio.h>

int main(){
    int num;
    int i = 1;
    int j, k;

    printf("Enter a number: ");
    scanf("%d",&num);
    printf("The Prime Factors of %d are: ", num);
    while(i <= num){
        k = 0;
        if(num % i == 0){
            j = 1;
            while(j <= i){
                if(i % j == 0){
                    k++;
                }
                j++;
            }
            if(k == 2){
                printf("%d\t", i);
            }
        }
        i++;
    }
    return 0;
}
