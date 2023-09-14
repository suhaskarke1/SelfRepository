# include<stdio.h>

int Addition(int ino1,int ino2)
{
     int sum =0;
	 sum=ino1+ino2;
	 
	 return sum;
}
int main()
{
   int iNo=0;
   int iNo2=0;
   int Ret=0;
   
   printf("Enter the First Number \n");
   scanf("%d",&iNo);
   
    printf("Enter the secound Number \n");
   scanf("%d",&iNo2);
   
   Ret=Addition(iNo,iNo2);
   
   printf("Addition is %d \n",Ret);
   return 0;
}