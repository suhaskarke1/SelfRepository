# include<stdio.h>
# include<stdlib.h>

// 5 : Perform the Operation on Array
int CountEven (int Arr[], int iSize)

{
	int iCnt =0;
	int iEvenCnt=0;
	
	for(iCnt=0;iCnt<iSize;iCnt++)
	{
		if((Arr[iCnt] %2)==0)
		{
			iEvenCnt++;
			
		}
	}
	return iEvenCnt;
	
	
}