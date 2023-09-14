# include<stdio.h>
# include<fcntl.h>

int main(int argc,char *argv[])
{

int fd=0;
	if(argc !=2)
	{
		printf("Invalid Number of Arguments \n");
		return -1;
	}
	fd=creat(argv[1],0777);
	if(fd ==-1)
	{
		printf("Unable to create the file ");
		return -1;
	}
	else
	{
		printf("File is create Successfully with fd %d \n",fd);
	}
	
	return 0;
	
}