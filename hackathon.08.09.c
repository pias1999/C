#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>

struct student{
    char ID[15];
    char name[20];

    int Class;
    long unsigned int phone_no;
};

struct student stu;

///This will set the forground color for printing in a console window.
void SetColor(int ForgC)
{
     WORD wColor;
     ///We will need this handle to get the current background attribute
     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO csbi;

     ///We use csbi for the wAttributes word.
     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
        ///Mask out all but the background attribute, and add in the forgournd color
          wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
     return;
}

void ClearConsoleToColors(int ForgC, int BackC)
{
     WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
     ///Get the handle to the current output buffer...
     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     ///This is used to reset the carat/cursor to the top left.
     COORD coord = {0, 0};
     ///A return value... indicating how many chars were written
     ///   not used but we need to capture this since it will be
     ///   written anyway (passing NULL causes an access violation).
     DWORD count;
     ///This is a structure containing all of the console info
     /// it is used here to find the size of the console.
     CONSOLE_SCREEN_BUFFER_INFO csbi;
     ///Here we will set the current color
     SetConsoleTextAttribute(hStdOut, wColor);
     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
          ///This fills the buffer with a given character (in this case 32=space).
          FillConsoleOutputCharacter(hStdOut, (TCHAR) 32, csbi.dwSize.X * csbi.dwSize.Y, coord, &count);
          FillConsoleOutputAttribute(hStdOut, csbi.wAttributes, csbi.dwSize.X * csbi.dwSize.Y, coord, &count );
          ///This will set our cursor position for the next print statement.
          SetConsoleCursorPosition(hStdOut, coord);
     }
     return;
}

void SetColorAndBackground(int ForgC, int BackC)
{
     WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);;
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
     return;
}

COORD coord = {0,0}; ///set the cordinate to 0, 0 (top-left corner of window);
void gotoxy(int x, int y){
    coord.X = x; coord.Y = y; /// X and Y coordinates
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void drawRectangle(){
    int i, j;
    gotoxy(0,0);
    printf("%c",201);
    for(i = 1; i < 78; i++){
        gotoxy(i, 0);
        printf("%c",205);
    }
    gotoxy(78,0);
    printf("%c",187);
    for(i = 1; i < 25; i++){
        gotoxy(78, i);
        if(i == 6){
            printf("%c",185);
        }else{
            printf("%c",186);
        }
    }
    gotoxy(78, 25);
    printf("%c",188);
    for(i = 77; i > 0; i--){
        gotoxy(i,25);
        if(i == 35){
            printf("%c",202);
        }else{
            printf("%c",205);
        }
    }
    gotoxy(0,25);
    printf("%c",200);
    for(i = 24; i > 0; i--){
        gotoxy(0,i);
        if(i == 6){
            printf("%c",204);
        }else{
            printf("%c",186);
        }
    }

    for(i = 1; i < 78; i++){
        gotoxy(i,6);
        if(i == 35){
            printf("%c",203);
        }else{
            printf("%c",205);
        }
    }

    for(i = 7; i < 25; i++){
        gotoxy(35,i);
        printf("%c",186);
    }

}

void clearWindow(){
    int i,j;
    for(i = 37; i < 78; i++){
        for(j = 7; j < 25; j++){
            gotoxy(i,j);printf(" ");
        }
    }
    return;
}

void window(){
    drawRectangle();
    gotoxy(20,2);
    SetColor(0);
    printf("University of Liberal Arts Bangladesh");
    gotoxy(40,3);
    printf("\n                                 MOODLE");


    gotoxy(25,24);
    SetColor(17);

}

void get_password(char* pass)
{
    char temp_passP[25];
    int i=0;
     while(1)
    {
            temp_passP[i]=getch();
            if(temp_passP[i]==13){break;}
            else if(temp_passP[i]==8)
            {
                if(i!=0) {
                printf("\b \b");
                i--;
                } else {printf("\a");}
            }
            else
            {
                printf("*");
                *(pass+i) = temp_passP[i];
                i++;
            }
             *(pass+i)='\0';
     }
}

void use_pass_field(){
    int x = 15, y = 16;
    int use;
    char pass[10];
    SetColor(10);
    gotoxy(15,12);printf("The database is password protected.");
    gotoxy(15,13);printf(" Enter Valid username and password");
    SetColor(17);
    gotoxy(20,x);printf("USERNAME:- ");
    gotoxy(20,y);printf("PASSWORD:- ");
    gotoxy(34,x);scanf("%d",use);
    gotoxy(34,y);get_password(pass);
}

void print_heading(const char st[]){
    SetColorAndBackground(0,7);
    gotoxy(45,8);printf("%s",st);
    SetColorAndBackground(17,15);
}


void add_student(){
    clearWindow();
    print_heading("Log In");
    int print = 37;
    FILE *fp;
    fp = fopen("record.txt","ab+");
    SetColor(0);
    if(fp == NULL){
        MessageBox(0,"Error in Opening file\nMake sure your file is not write protected","Warning",0);

    }else{
        fflush(stdin);
        gotoxy(print,10);printf("ID: ");gets(stu.ID);
        //here you can confirms the ID
        gotoxy(print,12);printf("Name: ");gets(stu.name);
        fwrite(&stu, sizeof(stu), 1, fp);
        gotoxy(40,22); printf("The record is sucessfully added");
    }
    SetColor(28);
    fclose(fp);
    return;
}

void search_student(){
    clearWindow();
    print_heading("Search Record");
    SetColor(45);
    char s_id[15];
    int isFound = 0;
    gotoxy(37,10);printf("Enter ID to Search: ");fflush(stdin);
    gets(s_id);
    FILE *fp;
    fp = fopen("record.txt","rb");
    while(fread(&stu,sizeof(stu),1,fp) == 1){
        if(strcmp(s_id,stu.ID) == 0){
            isFound = 1;
            break;
        }
    }
    if(isFound == 1){
        gotoxy(37,12);printf("The record is Found");
        gotoxy(37,14);printf("ID: %s",stu.ID);
        gotoxy(37,15);printf("Name: %s",stu.name);


        gotoxy(37,18);printf("Class: %d",stu.Class);
        gotoxy(37,19);printf("Phone No: %ld",stu.phone_no);
    }else{
        gotoxy(37,12);printf("Sory, No record found in the database");
    }
    SetColor(28);
    fclose(fp);
    return;
}

void mod_student(){
    clearWindow();
    print_heading("Modify Record");
    SetColor(45);
    char s_id[15];
    int isFound = 0, print = 37;
    gotoxy(37,10);printf("Enter ID to Modify: ");fflush(stdin);
    gets(s_id);
    FILE *fp;
    fp = fopen("record.txt","rb+");
    while(fread(&stu, sizeof(stu),1,fp) == 1){
        if(strcmp(s_id, stu.ID) == 0){
            fflush(stdin);
            gotoxy(print,12);printf("ID: ");gets(stu.ID);
            gotoxy(print,13);printf("Name: ");gets(stu.name);


            gotoxy(print,16);printf("Class: ");scanf("%d",&stu.Class);
            gotoxy(print,17);printf("Phone Number: ");scanf("%ld",&stu.phone_no);
            fseek(fp,-sizeof(stu), SEEK_CUR);
            fwrite(&stu,sizeof(stu), 1, fp);
            isFound = 1;
            break;
        }
    }
    if(!isFound){
        gotoxy(print, 12);printf("No Record Found");
    }
    fclose(fp);
    SetColor(28);
    return;
}

void delete_student()
{
    clearWindow();
    print_heading("Delete Record");
    SetColor(45);
    char s_id[15];
    int isFound = 0, print = 37;
    gotoxy(37,10);printf("Enter ID to Modify: ");fflush(stdin);
    gets(s_id);
    FILE *fp, *temp;
    fp = fopen("record.txt","rb");
    temp = fopen("temp.txt", "wb");
    while(fread(&stu, sizeof(stu),1,fp) == 1){
        if(strcmp(s_id, stu.ID) == 0){
            fwrite(&stu,sizeof(stu),1,temp);
        }
    }
    fclose(fp);
    fclose(temp);
    remove("record.txt");
    rename("temp.txt","record.txt");
    gotoxy(37,12);printf("The record is sucessfully deleted");
    SetColor(28);
    return;
}
void calender()
{
        int month=8,week=4,day;


    printf("\n\n     August 2018");
printf("\n Su  M  T  W  T  F  S\n" );


        if (week==1 && month>0 && month<=12)
            if (month == 1 || month == 3 || month ==5 || month ==7 || month ==8 || month == 10 || month ==12)
            for (day=1;day<=31;day++)
                if (day==7 || day==14 || day==21 || day==28)
                printf("%3d\n",day);
                else
                printf("%3d",day);
            else if (month ==4 || month==6 || month ==9 ||month==11 )
            for (day=1;day<=30;day++)
                if (day==7 || day==14 || day==21 || day==28)
                printf("%3d\n",day);
                else
                printf("%3d",day);
            else
            for (day=1;day<=29;day++)
                if (day==7 || day==14 || day==21 || day==28)
                printf("%3d\n",day);
                else
                printf("%3d",day);

        else if (week==2 && month>0 && month<=12)
            if (month == 1 || month == 3 || month ==5 || month ==7 || month ==8 || month == 10 || month ==12)
            for (day=1;day<=31;day++)
                if (day==6 || day==13 || day==20 || day==27)
                printf("%3d\n",day);
                else if (day==1)
                printf("   %3d",day);
                else
                printf("%3d",day);
            else if (month ==4 || month==6 || month ==9 ||month==11 )
            for (day=1;day<=30;day++)
                if (day==6 || day==13 || day==20 || day==27)
                printf("%3d\n",day);
                else if (day==1)
                printf("   %3d",day);
                else
                printf("%3d",day);
            else
            for (day=1;day<=29;day++)
                if (day==6 || day==13 || day==20 || day==27)
                printf("%3d\n",day);
                else if (day==1)
                printf("   %3d",day);
                else
                printf("%3d",day);

        else if (week==3 && month>0 && month<=12)
            if (month == 1 || month == 3 || month ==5 || month ==7 || month ==8 || month == 10 || month ==12)
            for (day=1;day<=31;day++)
                if (day==5 || day==12 || day==19 || day==26)
                printf("%3d\n",day);
                else if (day==1)
                printf("      %3d",day);
                else
                printf("%3d",day);
            else if (month ==4 || month==6 || month ==9 ||month==11 )
            for (day=1;day<=30;day++)
                if (day==5 || day==12 || day==19 || day==26)
                printf("%3d\n",day);
                else if (day==1)
                printf("      %3d",day);
                else
                printf("%3d",day);
            else
            for (day=1;day<=29;day++)
                if (day==5 || day==12 || day==19 || day==26)
                printf("%3d\n",day);
                else if (day==1)
                printf("      %3d",day);
                else
                printf("%3d",day);

        else if (week==4 && month>0 && month<=12)
            if (month == 1 || month == 3 || month ==5 || month ==7 || month ==8 || month == 10 || month ==12)
            for (day=1;day<=31;day++)
                if (day==4 || day==11 || day==18 || day==25)
                printf("%3d\n",day);
                else if (day==1)
                printf("         %3d",day);
                else
                printf("%3d",day);
            else if (month ==4 || month==6 || month ==9 ||month==11 )
            for (day=1;day<=30;day++)
                if (day==4 || day==11 || day==18 || day==25)
                printf("%3d\n",day);
                else if (day==1)
                printf("         %3d",day);
                else
                printf("%3d",day);
            else
            for (day=1;day<=29;day++)
                if (day==4 || day==11 || day==18 || day==25)
                printf("%3d\n",day);
                else if (day==1)
                printf("         %3d",day);
                else
                printf("%3d",day);


        else if (week==5 && month>0 && month<=12)
            if (month == 1 || month == 3 || month ==5 || month ==7 || month ==8 || month == 10 || month ==12)
            for (day=1;day<=31;day++)
                if (day==3 || day==10 || day==17 || day==24 || day==31)
                printf("%3d\n",day);
                else if (day==1)
                printf("            %3d",day);
                else
                printf("%3d",day);
            else if (month ==4 || month==6 || month ==9 ||month==11 )
            for (day=1;day<=30;day++)
                if (day==3 || day==10 || day==17 || day==24)
                printf("%3d\n",day);
                else if (day==1)
                printf("            %3d",day);
                else
                printf("%3d",day);
            else
            for (day=1;day<=29;day++)
                if (day==3 || day==10 || day==17 || day==24)
                printf("%3d\n",day);
                else if (day==1)
                printf("            %3d",day);
                else
                printf("%3d",day);

        else if (week==6 && month>0 && month<=12)
            if (month == 1 || month == 3 || month ==5 || month ==7 || month ==8 || month == 10 || month ==12)
            for (day=1;day<=31;day++)
                if (day==2 || day==9 || day==16 || day==23 || day==30)
                printf("%3d\n",day);
                else if (day==1)
                printf("               %3d",day);
                else
                printf("%3d",day);
            else if (month ==4 || month==6 || month ==9 ||month==11)
            for (day=1;day<=30;day++)
                if (day==2 || day==9 || day==16 || day==23 || day==30)
                printf("%3d\n",day);
                else if (day==1)
                printf("               %3d",day);
                else
                printf("%3d",day);
            else
            for (day=1;day<=29;day++)
                if (day==2 || day==9 || day==16 || day==23)
                printf("%3d\n",day);
                else if (day==1)
                printf("               %3d",day);
                else
                printf("%3d",day);

        else if (week==7 && month>0 && month<=12)
            if (month == 1 || month == 3 || month ==5 || month ==7 || month ==8 || month == 10 || month ==12)
            for (day=1;day<=31;day++)
                if (day==8 || day==15 || day==22 || day==29)
                printf("%3d\n",day);
                else if (day==1)
                printf("                  %3d\n",day);
                else
                printf("%3d",day);
            else if (month ==4 || month==6 || month ==9 ||month==11 )
            for (day=1;day<=30;day++)
                if (day==8 || day==15 || day==22 || day==29)
                printf("%3d\n",day);
                else if (day==1)
                printf("                  %3d\n",day);
                else
                printf("%3d",day);
            else
            for (day=1;day<=29;day++)
                if (day==8 || day==15 || day==22 || day==29)
                printf("%3d\n",day);
                else if (day==1)
                printf("                  %3d\n",day);
                else
                printf("%3d",day);

    getch();
}

void courses()
{

    printf("\nMy courses\n\n");
    printf("WORLD CIVILIZATION\n");
    printf("Teacher: Ms. Afsana Anjum\n\n");
    printf("DATA STRUCTURES\n");
    printf("Teacher: Dr. Muzahidul Islam\n\n");
    printf("DATA STRUCTURES LAB\n");
    printf("Teacher: Dr. Muzahidul Islam\n\n");
    printf("DIFFERENTIAL EQUATIONS\n");
    printf("Teacher: Mr. Khan Raqib Mahmud\n\n");
    printf("Press 1 for World Civilization & 10 for Course faculty\nPress 2 for Data Structures, 3 for Lab & 20 for Course faculty\nPress 4 for Differential Equations & 40 for Course faculty\n\n");




    int choice;
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        {
            printf(" World Civilization\n");
            printf(" Home > My courses > Summer 2018 > General Education > GED201-7-SU18\n\n");
            printf(" 1 May - 7 May\n 8 May - 14 May\n 5 May - 21 May\n 22 May - 28 May\n 29 May - 4 June\n 5 June - 11 June\n 12 June - 18 June\n 19 June - 25 June\n 26 June - 2 July\n 3 July - 9 July\n\n");
        }
        break;
    case 2:
        {
            printf(" Data Structures\n");
            printf(" Home > My courses > Summer 2018 > Computer Science and Engineering > CSE207-2-SU18\n\n");
            printf(" 1 May - 7 May\n 8 May - 14 May\n 5 May - 21 May\n 22 May - 28 May\n 29 May - 4 June\n 5 June - 11 June\n 12 June - 18 June\n 19 June - 25 June\n 26 June - 2 July\n 3 July - 9 July\n\n");
        }
        break;
    case 3:
        {
            printf(" Data Structures Lab\n");
            printf(" Home > My courses > Summer 2018 > Computer Science and Engineering > CSE208-2-SU18\n\n");
            printf(" 1 May - 7 May\n 8 May - 14 May\n 5 May - 21 May\n 22 May - 28 May\n 29 May - 4 June\n 5 June - 11 June\n 12 June - 18 June\n 19 June - 25 June\n 26 June - 2 July\n 3 July - 9 July\n\n");
        }
        break;
    case 4:
        {
            printf(" Differential Equations\n");
            printf(" Home > My courses > Summer 2018 > Computer Science and Engineering > MAT201-2-SU18\n\n");
            printf(" 1 May - 7 May\n 8 May - 14 May\n 5 May - 21 May\n 22 May - 28 May\n 29 May - 4 June\n 5 June - 11 June\n 12 June - 18 June\n 19 June - 25 June\n 26 June - 2 July\n 3 July - 9 July\n\n");
        }
        break;
    case 10:
        {
            printf(" Ms. Afsana Anjum\n Country: Bangladesh\n City/town: Dhaka\n Course profiles: Bangladesh Studies, World Civilization, World Civilization, World Civilization, Bangladesh Studies\n\n");
        }
        break;
    case 20:
        {
            printf(" Dr. Muzahidul Islam\n Country: Bangladesh\n City/town: Dhaka\n Course profiles: Project, Data Structures Lab, Data Structures, Operating Systems, Data Structures Lab, Data Structures\n\n");
        }
        break;
    case 40:
        {
            printf(" Mr. Khan Raqib Mahmud\n Country: Bangladesh\n City/town: Dhaka\n Course profiles: Introduction to Computer Studies, Differential and Integral Calculus, Differential Equations , Differential Equations , Mathematical Methods, Introduction to Computer Studies\n\n");
        }
        break;
    case 5:
        exit(0);
        break;
    default:
        break;
    }

}

void activities()
{
    printf("\n\nRECENT ACTIVITY\n");
    printf("\nNothing new since your last login\n");
}

void events()
{
    printf("\nThere are no upcoming events\n\n");
    printf("Press 1 to go to Calender\nPress 0 to exit\n");
    int choice;
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        calender();
        break;
    case 0:
        exit(0);
        break;
    }
}


void main_window(){
    int choice;
    SetColor(25);
    int x = 2;
    while(1)
{

        gotoxy(x,8);printf("1. Log In");
        gotoxy(x,10);printf("2. Search");
        gotoxy(x,12);printf("3. Courses");
        gotoxy(x,14);printf("4. Calender");
        gotoxy(x,16);printf("5. profile settings");
        gotoxy(x,18);printf("6. Activities");
        gotoxy(x,20);printf("7. Events");
        gotoxy(x,22);printf("8. Forum");
        gotoxy(x,24);printf("9. Remove");
        gotoxy(x,26);printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                add_student();
                break;
            case 2:
                search_student();
                break;
            case 3:
                courses();
                break;
            case 4:
                calender();
                break;
            case 5:
                mod_student();
                break;
            case 6:
                activities();
                break;
            case 7:
                events();
                break;
            case 8:
                delete_student();
            case 9:
                exit(0);
                break;
            default:
                break;
        }

    }

}

int main(){
    ClearConsoleToColors(17,15);
    SetConsoleTitle("http://moodle.ulab.edu.bd");
    window();
    //use_pass_field();
    main_window();
    return 0;
}
