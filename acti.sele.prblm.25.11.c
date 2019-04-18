#include <stdio.h>

void activity(int start[], int end[], int n){
   printf("SELECTED ACTIVITIES INDICES ARE: ");
   printf("0 ");
   // first activity is always selected
   int j,i = 0;
   //for all the activities
   for(j = 1; j < n; j++)
      /* If this activity has start time greater than or
       equal to the finish time of previously selected
       activity, then select it */
      if(start[j] >= end[i]){
            printf("%d ",j);
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
   activity(start, end, n);

   return 0;
}
