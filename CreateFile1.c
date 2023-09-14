# include<stdio.h>
# include<unistd.h>
# include<fcntl.h>
# include<stdlib.h>

int main(int argc,char *argv[])
{
    int fd=0;
	
	if(argc !=2)
	{
		printf("Insufficent Arguments \n");
		return -1;
	}
	 
	 fd=open(argv[1],O_RDWR);
	 if(fd !=-1)
	 {
		 printf("File is Existing \n");
		 
	 }
	 else
	 {
		 fd=creat(argv[1],0777);
		 if(fd!=-1)
		 {
			 printf("New file gets created \n");
		 }
	
	
}
return 0;
}