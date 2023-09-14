# include<stdio.h>
# include<unistd.h>
# include<stdlib.h>

int main()
{
	int PID=0;
	int Ret=0;
	
	Ret=fork();
	
	if(Ret==0)
	{
		printf("Chile Process is Running \n");
		printf("Child says : Pid Parent Process is : %d \n",getppid());
		printf("child says : Pid of child process is : %d \n",getpid());
	}
	else
	{
		printf("Parent Process is Running \n");
		printf("Parent says : Pid of child process is : %d \n",Ret);
		printf("Parent says : Pid of Parent process is : %d \n",getpid());
		printf("Parent says : Pid of Parent of Parent ie Terminal is : %d\n",getppid());
		
	}
	
return 0;

}
