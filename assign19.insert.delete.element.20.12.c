#include <stdio.h>

int main(){
   int ar[100];
   int pos;
   int i, length;
   int elem;

   printf("Enter the length of the array: ");
   scanf("%d", &length);

   for(i = 0; i < length; i++){
      printf("Enter element %d: ", i+1);
      scanf("%d", &ar[i]);
   }
   printf("Enter the position where you want to insert an element: ");
   scanf("%d", &pos);

   printf("Enter the element: ");
   scanf("%d", &elem);

   for(i = length - 1; i >= pos - 1; i--){
      ar[i+1] = ar[i];
   }
   ar[pos - 1] = elem;

   printf("The array after inserting %d at position %d is:\n", elem, pos);

   for(i = 0; i <= length; i++){
      printf("%d\t", ar[i]);
   }

   printf("\nEnter the location where you want to delete element: ");
   scanf("%d", &pos);

   for(i = pos - 1;i < length;i++){
         ar[i] = ar[i+1];
   }
      printf("\nThe array after deleting position %d is: \n", pos);
      for(i = 0;i < length;i++){
         printf("%d\t", ar[i]);
      }

   return 0;
}
