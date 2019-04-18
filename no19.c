#include <stdio.h>

int main(){
    int array[100], position, c, n, value, size, i;

    printf("Enter number of elements in array: ");
    scanf("%d", &n);

    printf("\nEnter %d elements:\n\n", n);
    for (c = 0; c < n; c++)
      scanf("%d", &array[c]);

    printf("\nEnter the position where you wish to insert an element\n");
    scanf("%d", &position);

    printf("Enter the value to insert\n");
    scanf("%d", &value);
    for (c = n - 1; c >= position - 1; c--)
      array[c+1] = array[c];

    array[position-1] = value;

    printf("\nElements of array after inserting: ");
        for (c = 0; c <= n; c++)
      printf("%d\t", array[c]);

    printf("\n\nEnter the location where you wish to delete element\n");
    scanf("%d", &position);

    if ( position >= n+1 )
      printf("Deletion not possible.\n");
    else {
      for ( c = position - 1 ; c < n ; c++ )
         array[c] = array[c+1];

      printf("Elements of array after deleting: ");

      for( c = 0 ; c < n ; c++ )
         printf("%d\t", array[c]);
   }
}
