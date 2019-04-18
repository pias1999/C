#include <stdio.h>
#include <math.h>

int main(){

    int i;
    int hours = 0;
    double overtime;


    for (i = 1; i < 11; i++){
        printf("Overtime done by Employee %d :\t", i);
        scanf("%d", &hours);
        overtime = hours * 12;
        printf("Total Overtime Payment of %dno. employees is %0.2lf\n\n", i,overtime);
       }

    return 0;
}
