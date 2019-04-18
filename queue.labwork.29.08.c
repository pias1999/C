#include <stdio.h>
#define MAX 50

int arr[MAX];
int rear = -1;
int front = -1;

void enqueue(){
    int j, ch, add;
    if(rear == MAX - 1)
    printf("Queue Full. \n");
    else{
        if(front == - 1)
        front = 0;
        printf("\nHow many objects you want to input: ");
        scanf("%d", &ch);
        printf("\n");
        for(j = 1; j <= ch; j++){
        printf("Enter element %d: ", j);
        scanf("%d", &add);
        rear = rear + 1;
        arr[rear] = add;
    }
    }
    printf("\n");
}

void dequeue(){
    if(front == - 1 || front > rear){
        printf("Queue Empty. \n");
    }
    else{
        printf("Element deleted from queue is : %d\n", arr[front]);
        front = front + 1;
    }
    printf("\n");
}

void display(){
    int i;
    if (front == - 1){
    printf("Queue is empty. \n");
    }else{
    printf("\nQueue is: ");
    for (i = front; i <= rear; i++)
    printf("%d ", arr[i]);
    printf("\n\n");
   }
}

int main(){
    int choice;
    while(1){
        printf("1.Insert elements. \n");
        printf("2.Delete elements. \n");
        printf("3.Display all elements. \n");
        printf("4.Quit \n");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
            enqueue();
//            printf("Press any key to continue.\n\n");
//            getch();
            break;
            case 2:
            dequeue();
//            printf("Press any key to continue.\n\n");
//            getch();
            break;
            case 3:
            display();
//            printf("Press any key to continue.\n\n");
//            getch();
            break;
            case 4:
            exit(1);
            default:
            printf("Wrong choice \n");
        }
    }
}


