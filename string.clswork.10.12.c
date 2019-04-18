#include <stdio.h>
#include <string.h>

int main(){
    char str[12] = "Hello";
    char str1[12] = "World";

    printf("Original Value: %s", str);
    strcpy(str, str1); //copying str1 to str.
    printf("\nAfter Copy: %s", str);

    printf("\nLength of %s is: %d", str, strlen(str));

    strcat(str, str1); //adding str1 onto the end of str.
    printf("\nAfter joining: %s", str);

    //lets compare strings
    char bd[12] = "Bangladesh";
    char bd1[12] = "Bangladesh";

    if(strcmp(bd, bd1) == 0){
        printf("\nMatch Found");
    }else{
        printf("\nNo Match Found");
    }


return 0;
}
