# include<stdio.h>

int Factorial(int iNo)
{
   int iFact=1;
   int iCnt=0;
   for(iCnt=1;iCnt<=iNo;iCnt++)
   {
     iFact=iFact*iCnt;
   }
   return iFact;
}
int main()
{
  int iValue=0;
  int iret=0;
  
  printf("Please Enter The Number \n");
  scanf("%d",&iValue);
  
  iret=Factorial(iValue);
  
  printf("The Factorial is %d : %d\n",iValue,iret);
  
  return 0;
}
