# include<stdio.h>

int Reverse(int iNo)
{
	int iDigit=0;
	int iRev=0;
	
	if(iNo<0)
	{
		iNo=-iNo;
	}
	while(iNo!=0)
	{
		iDigit=iNo %10;
		iRev=(iRev *10)+iDigit;
		iNo=iNo/10;
	}
	return iRev;
}
int main()
{
	int iValue=0;
	int iRet=0;
	
	
	printf("Please Enter The Number \n");
	scanf("%d",&iValue);
	
	iRet=Reverse(iValue);
	
	printf("the Reverse Number is %d \n",iRet);
	
	return 0;
}