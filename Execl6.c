# include<stdio.h>
# include<unistd.h>
# include<stdlib.h>

int main()
{
  int Ret=0;
  
  Ret=fork();
  if(Ret==0)
  {
	  execl("./ChildProcess","NULL",NULL);
  }
  else
  {
	  printf("Parent is running with PID %d \n",getpid());
	  sleep(1000);
  }
return 0;
}