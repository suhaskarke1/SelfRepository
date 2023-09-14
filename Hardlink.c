# include<stdio.h>
# include<stdlib.h>
#include<unistd.h>

int main()
{
   char Filename1[30],Filename2[30];
   int Ret=0;
   
   printf("Entr the Existing file name \n");
   scanf("%s",&Filename1);
   
   printf("Enter the file name for hardlink :\n");
   scanf("%s",&Filename2);
   Ret=link(Filename1,Filename2);
   
   if(Ret==0)
   {
     printf("Hardlink creadetd sucessfully \n");
	 
   }
return 0;
}