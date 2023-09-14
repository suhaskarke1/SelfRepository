# include<stdio.h>

int Min(int iNo)
{
	int iDigit=0;
	int iMin=9;
	
	if(iNo<0)
	{
		iNo=-iNo;
	}
	
	while(iNo !=0)
	{
		iDigit=iNo%10;
		 if(iDigit< iMin)
		 {
			 iMin=iDigit;
			
		 }
		  iNo=iNo/10;
}
		 return iMin;
}
int main()
{
    int iValue=0;
	int iRet=0;
	printf("Please Enter The Number\n");
	scanf("%d",&iValue);
	
	iRet=Min(iValue);
	
	printf("The Minimum Number is %d \n",iRet);
	

return 0;
}