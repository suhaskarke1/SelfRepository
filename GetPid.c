# include<stdio.h>
# include<unistd.h>
# include<stdlib.h>

int main()
{
	int PID=0;
	
	PID=getpid();
	printf("PID of running process is %d\n",PID);
	
	return 0;
}