#include <stdio.h>

int main(){
    int i;
    int num;
    int r;
    int qub;
    int sum;
    printf("The Armstrong numbers between 1 to 500 are:\n");

    for(i = 1; i <= 500; i++){
        num = i;
        sum = 0;

        while(num > 0){
            r = num % 10;
            qub = r * r * r;
            sum = sum + qub;
            num = num / 10;
        }
        if(sum == i){
            printf("%d\n", sum);
        }
    }
    return 0;
}
