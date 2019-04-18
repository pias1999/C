#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 100

int array[SIZE],k;
FILE *input, *output;
void quicksort(int num[SIZE],int first,int last){
   int i,j,temp,pivot;

   if(first < last){
           pivot = last;
           i = first;
           j = last;

           while(i < j){
                   while(num[i] <= num[pivot] && i<last)
                   i++;
                       while(num[j] > num[pivot])
                           j--;
                           if(i < j){
                               temp = num[i];
                               num[i] = num[j];
                               num[j] = temp;
                           }
               }
               temp = num[pivot];
               num[pivot] = num[j];
               num[j] = temp;
               quicksort(num, first, j-1);
               quicksort(num, j+1, last);
       }
}

int main(){
   input = fopen("input.txt","w");
   srand(time(0));

   for(k = 0;k < SIZE;k++){
           array[k] = rand();
       }

   for(k = 0;k < SIZE;k++){
           fprintf(input,"%d\n", array[k]);
       }

   if(input == NULL){
           printf("Error Occurred!");
           exit(1);
       }
   fclose(input);

   printf("Quick sort completed successfully.");
   clock_t t;
   t = clock();

   quicksort(array, 0, SIZE-1);

   t = clock();
   double time_taken=((double)t) / CLOCKS_PER_SEC;

   printf("\n");
   printf("Time taken to execute: %f\n", time_taken);
   output = fopen("output.txt","w");

   for(k = 0;k < SIZE; k++){
       fprintf(output,"%d\n",array[k]);
   }

   if(output == NULL){
      printf("Error! Opening File");
      exit(1);
   }

   fclose(output);

   return 0;
}
