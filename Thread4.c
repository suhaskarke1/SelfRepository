# include<stdio.h>
# include<stdlib.h>
# include<unistd.h>
# include<fcntl.h>
# include<pthread.h>

void * ThreadProc1(void * ptr)
{
	int fd=0;
	int Ret=0;
	int i=0;
	int iCnt=0;
	char Buffer[512];
	
	fd=open("Demo.txt",O_RDONLY);
	 
	 while((Ret=read(fd,Buffer,sizeof(Buffer)))!=0)
	  {
		  for(i=0;i<Ret;i++)
		  {
			  if((Buffer[i]>='a')&&(Buffer[i]<='z'))
			  {
				  iCnt++;
			  }
		  }
		 
	  }
	  printf("Number of  small character are %d \n",iCnt);
	  
	 close(fd);
	 pthread_exit(NULL);
		 
}
void * ThreadProc2(void * ptr)
{
	int fd=0;
	int Ret=0;
	int i=0;
	int iCnt=0;
	char Buffer[512];
	
	fd=open("Demo.txt",O_RDONLY);
	  while((Ret=read(fd,Buffer,sizeof(Buffer)))!=0)
	  {
		  for(i=0;i<Ret;i++)
		  {
			  if((Buffer[i]>='A')&&(Buffer[i]<='Z'))
			  {
				  iCnt++;
			  }
		  }
		 
	  }
	  printf("Number of  Capital character are %d \n",iCnt);
	  
	 close(fd);
	 pthread_exit(NULL);
		 
}

void * ThreadProc3(void * ptr)
{
	int fd=0;
	int Ret=0;
	int i=0;
	int iCnt=0;
	char Buffer[512];
	
	fd=open("Demo.txt",O_RDONLY);
	  while((Ret=read(fd,Buffer,sizeof(Buffer)))!=0)
	  {
		  for(i=0;i<Ret;i++)
		  {
			  if(Buffer[i]==' ')
			  {
				  iCnt++;
			  }
		  }
		 
	  }
	  printf("Number of  Whitespce  are %d \n",iCnt);
	  
	 close(fd);
	 pthread_exit(NULL);
		 
}
void * ThreadProc4(void * ptr)
{
	int fd = 0 , Length = 0;
    char Data[100];
    int Count = 0, i = 0;
	
	fd=open("Demo.txt",O_RDONLY);
	 if(fd == -1)
    {
        printf("Unable to open file\n");
        return -1;
    }
    
    while((Length = read(fd,Data,sizeof(Data))) != 0)
    {
        for(i = 0; i < Length; i++)
        {
            if(Data[i] >= '0' && Data[i] <= '9')
            {
                Count++;
            }
        }
    }
	  printf("Number of  Digit  are %d \n",Count);
	  
	 close(fd);
	 pthread_exit(NULL);
		 
}

int main()
{
	pthread_t TID1,TID2,TID3,TID4;
	
	int Ret1=0;
	int Ret2=0;
	int Ret3=0;
	int Ret4=0;
	Ret1=pthread_create(&TID1,NULL,ThreadProc1,NULL);
	
	if(Ret1 !=NULL)
	{
		printf("Unable to create Thread \n");
		return -1;
	}
	//printf("Thread is Created with ID %d \n",TID1); 
	
	Ret2=pthread_create(&TID2,NULL,ThreadProc2,NULL);
	
	if(Ret2 !=NULL)
	{
		printf("Unable to create Thread \n");
		return -1;
	}
	
	//printf("Thread is Created with ID %d \n",TID2);
	
	Ret3=pthread_create(&TID3,NULL,ThreadProc3,NULL);
	
	if(Ret3 !=NULL)
	{
		printf("Unable to create Thread \n");
		return -1;
	}
	//printf("Thread is Created with ID %d \n",TID3);
	
	Ret4=pthread_create(&TID4,NULL,ThreadProc4,NULL);
	
	if(Ret4 !=NULL)
	{
		printf("Unable to create Thread \n");
		return -1;
	}
	//printf("Thread is Created with ID %d \n",TID4);
	 
	 
	 
	
	pthread_join(TID1,NULL);
	pthread_join(TID2,NULL);
	pthread_join(TID3,NULL);
	pthread_join(TID4,NULL);
	printf("End of main Thread \n");
	
	pthread_exit(NULL);
	
	
	return 0;
}