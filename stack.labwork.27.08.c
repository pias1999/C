#include <stdio.h>
#define MAXSIZE 50

int stack[MAXSIZE], choice, n, top, x, i;
void push();
void pop();
void display();

void push(){

    if(top >= n - 1){
        printf("\n\tSTACK is over flow");
    }else{
        printf("Enter a value to be pushed:");
        scanf("%d", &x);
        top++;
        stack[top] = x;
    }
}

void pop(){

    if(top <= -1){
        printf("\n\tStack is under flow");
    }else{
        printf("\n\tThe popped elements is %d",stack[top]);
        top--;
    }
}
void display(){

    if(top >= 0){
        printf("\nThe elements in STACK: ");
        for(i = top; i >= 0; i--)
            printf("%d ", stack[i]);
        printf("\nPress Next Choice");
    }else{
        printf("\nThe STACK is empty");
    }

}

int main(){
    top = -1;
    printf("Enter the size of STACK: ");
    scanf("%d", &n);

    while(choice != 4){
        printf("\n\tSTACK OPERATIONS USING ARRAY");
        printf("\n\n\t 1.PUSH\n\t 2.POP\n\t 3.DISPLAY\n\t 4.EXIT");
        printf("\nEnter the Choice:");
        scanf("%d", &choice);
        switch(choice){
            case 1:{
                push();
                break;
            }
            case 2:{
                pop();
                break;
            }
            case 3:{
                display();
                break;
            }
            case 4:{
                printf("\n\t EXIT POINT ");
                break;
            }
            default:{
                printf ("\n\t Please Enter a Valid Choice(1/2/3/4)");
            }

        }
    }

    return 0;
}
