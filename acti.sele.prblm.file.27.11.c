#include <stdio.h>

FILE *input, *output;
void activity(int start[], int end[], int n){
   int j=0,i = 0;
   output = fopen("output.txt", "w");
   printf("SELECTED ACTIVITIES INDICES ARE: ");
   printf("0 ");
   fprintf(output,"Selected activities are: %d ",j);

   for(j = 1; j < n; j++)
      if(start[j] >= end[i]){
            printf("%d ",j);
            fprintf(output,"%d ",j);
            i = j;
          }

}

int main(){
   int n, i;
   printf("Enter size of list: ");
   scanf("%d", &n);
   int start[n], end[n];
   printf("Enter start time and end time simultaneously: \n");
   for(i = 0;i < n; i++)
      scanf("%d %d", &start[i], &end[i]);
   input = fopen("input.txt", "w");
   for(i=0;i<n;i++){
       fprintf(input, "Start time: %d\tEnd time: %d\n", start[i], end[i]);
   }

   activity(start, end, n);

   return 0;
}
