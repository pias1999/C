#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#define SIZE 1000

void merge(int arr[], int l, int m, int r){
   int i, j, k;
   int n1 = m - l + 1;
   int n2 = r - m;

   int L[n1], R[n2];

   for(i = 0; i < n1; i++){
       L[i] = arr[l + i];
   }for(j = 0; j < n2; j++){
       R[j] = arr[m + 1 + j];
   }

   i = 0;
   j = 0;
   k = l;
   while(i < n1 && j < n2){
       if (L[i] <= R[j]){
           arr[k] = L[i];
           i++;
       }
       else
       {
           arr[k] = R[j];
           j++;
       }
       k++;
   }

   while (i < n1){
       arr[k] = L[i];
       i++;
       k++;
   }

   while (j < n2){
       arr[k] = R[j];
       j++;
       k++;
   }
}

void mergeSort(int arr[], int l, int r){
   if(l < r){
       int m = l+(r-l)/2;
       mergeSort(arr, l, m);
       mergeSort(arr, m+1, r);
       merge(arr, l, m, r);
   }
}

int main(){
   int arr[SIZE],j,k,l;
   srand(time(0));

   for(j=0;j<SIZE;j++)
   {
       arr[j] = rand();
   }

   FILE *fp, *fw ;
   fp = fopen("input.txt", "w");

   for(k=0;k<SIZE;k++){
       fprintf(fp, "%d\n", arr[k]);
   }
   fclose(fp);
   clock_t t;
   t = clock();

   mergeSort(arr,0,SIZE-1);

   t = clock();

   double time_taken = ((double)t)/CLOCKS_PER_SEC;
   printf("Time taken to execute: ");
   printf("%f", time_taken);

   fw = fopen ("output.txt", "w");
   for(l=0;l<SIZE;l++){
       fprintf(fw,"%d\n",arr[l]);
   }

   fclose(fw);
   return 0;
}
