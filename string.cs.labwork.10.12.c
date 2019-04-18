#include <stdio.h>
#include <string.h>

int main(){
    char i[200] = "My name is \"Ashikuzzaman Pias\".";
    char j[50] = "I am from";
    char k[30] = "Dhaka, Bangladesh";

    strcat(i,j);
    printf("%s", i);

    strcat(j,k);
    printf(" %s.", k);
    printf("\n\nLength  is: %d", strlen(i));


return 0;
}
