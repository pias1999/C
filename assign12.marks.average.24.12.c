#include <stdio.h>

int main(){
    int i, s, cour;
    double marks;
    double total, average, perc;

    printf("Enter number of courses: ");
    scanf("%d", &cour);

    for(i = 0; i < cour; i++){
     printf("Enter marks of course %d: ", i+1);
     scanf("%lf", &marks);
     total += marks;
    }
    average = total / cour;
    perc = (total / (cour * 100)) * 100;

    printf("Average of %d courses: %0.2lf\n", cour, average);
    printf("Percentage of %d courses: %0.2lf\%\%", cour, perc);

    return 0;
}
