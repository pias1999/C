#include <stdio.h>
#define MAX

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

// A function to implement bubble sort
void bubbleSort(int arr[], int n){
   int i, j;
   for (i = 0; i < n-1; i++){

       // Last i elements are already in place
       for (j = 0; j < n-i-1; j++){
           if (arr[j] > arr[j+1])
              swap(&arr[j], &arr[j+1]);
    }
  }
}

/* Function to print an array */
void printArray(int arr[], int size){
    int i;
    for (i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
}

// Driver program to test above functions
int main(){
    int a;
    int arr[] = {64, 34, 25, 12, 22};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("The array is: ");
    printArray(arr, n);

    bubbleSort(arr, n);

    printf("\n\nSorted array: ");
    printArray(arr, n);

    return 0;
}
