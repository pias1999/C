#include <stdio.h>
#include <math.h>

int main(){
   int i;
   int j, num[100];
   double sum = 0, sum1 = 0;

   printf("Enter how many integers you wanna input: ");
   scanf("%d", &j);

   for (i = 0; i < j; i++){
      printf("Enter integer %d: ", i+1);
      scanf("%d", &num[i]);
      sum +=  num[i];
   }

   double average = sum / j;
   printf("Sum of %d integers: %0.2lf\n", j, sum);
   printf("Average of %d integers: %0.2lf", j, average);

   for (i = 0; i < j; i++){
        sum1 += pow((num[i] - average), 2);
    }
    double var = sum1 / j;
    printf("\nVariance of %d integers: %0.2lf", j, var);
    printf("\nStandard Deviation of %d integers: %0.2lf", j, sqrt(var));

   return 0;
}
