#include <stdio.h>
#include <stdlib.h>

#define MAXCHAR 1000
int main(){
   FILE *f;
   char sent[MAXCHAR];
   char file[MAXCHAR];

   printf("Enter the filename: ");
   gets(file);

   printf("Please enter Inputs:\n");
   gets(sent);
   f = fopen(file, "w");
   if(f){
      fprintf(f,"%s", sent);
   }else{
      printf("Error!");
      exit(0);
   }
   fclose(f);

   return 0;
}
/*
#include <stdio.h>

int main()
{
 FILE *fp;
 char filename[100];
 char writestr[100];

  // Read filename
  printf("Enter a filename :");
  gets(filename);

  // Read string to write
  printf("Enter the string to write :");
  gets(writestr);

   // Open file in write mode
   fp = fopen(filename,"w+");

   // If file opened successfully, then write the string to file
   if ( fp )
   {
	   fputs(writestr,fp);
    }
   else
      {
         printf("Failed to open the file\n");
        }
//Close the file
   fclose(fp);
return(0);
}
*/
