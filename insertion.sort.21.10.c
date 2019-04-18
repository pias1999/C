#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sorting(){
    int a[10];
    int i,j,n,temp;
    printf("How many values you want to sort: ");
    scanf("%d", &n);
    for(i=0; i < n; i++){
        printf("Enter value %d: ", i + 1);
        scanf("%d", &a[i]);
    }
    FILE *fp;
    fp = fopen("pias.txt", "w");
    for(i=0; i < n; i++){
        fprintf(fp, "%d\n", a[i]);
    }
    fclose(fp);

    for(i = 0;i < n;i++){
		temp = a[i];
		j = i - 1;
		while(temp < a[j] && j >= 0)
		{
			a[j + 1] = a[j];
			--j;
		}
		a[j + 1]=temp;
	}

    FILE *fp2;
    fp2 = fopen("pias2.txt", "w");
    for(j = 0; j < n; j++){
        fprintf(fp2, "%d\n", a[j]);
    }
    printf("File has been sorted.");
    printf("\nPress any key to see the execution time.");
}

void times(){
   clock_t t;
   t = clock();

   while(1){
       if(getchar())
           break;
   }

   t = clock() - t;
   double time_taken = ((double)t)/CLOCKS_PER_SEC;

   printf("\nTime taken to execute: %f", time_taken);
}

int main(){
    sorting();
    times();
}
