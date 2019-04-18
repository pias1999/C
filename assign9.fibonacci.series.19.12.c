#include <stdio.h>
int main(){
    int i;
    int n;
    int term1 = 0;
    int term2 = 1;
    int next;

    printf("Enter the range of Fibonacci series: ");
    scanf("%d", &n);

    printf("%d range Fibonacci Series: ", n);

    for (i = 1; i <= n; ++i){
        printf("%d\t", term1);
        next = term1 + term2;
        term1 = term2;
        term2 = next;
    }
    return 0;
}
