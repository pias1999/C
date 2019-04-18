#include<stdio.h>
int main(){
    int i;
    double marks[3],ave=0,total=0;

    printf("Enter obtained marks of 3 courses out of 80\n");

    for(i=1;i<4;i++){

    printf("\nCourse %d : ",i);

    scanf("%lf",&marks[i]);

    total=total+marks[i];

     printf("\nPercentage of course %d is : %0.1lf%\n",i,(marks[i]*100)/100);
    }
    ave=total/3;

    printf("\nObtained average mark : %lf\n",ave);

    printf("\nObtained total percentage :%lf\n",(total*100)/300);

    return 0;
}
