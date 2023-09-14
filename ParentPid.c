# include<stdio.h>
# include<unistd.h>
# include<stdlib.h>

int main()
{
	int PID=0;
	int PPID=0;
	
	PID=getpid();
	printf("PID of running process is %d \n",PID);
	
	PPID=getppid();
	printf("PID of Parent Process is %d \n",PPID);
	
	return 0;
}