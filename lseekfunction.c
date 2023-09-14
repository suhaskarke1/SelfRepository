# include<stdio.h>
# include<stdlib.h>
# include<unistd.h>
# include<fcntl.h>

int main(int argc,char *argv[])
{
	int fd=0;
	int ret=0;
	char Arr[20];
	
	fd=open(argv[1],O_RDONLY);
	if(fd==-1)
	{
		printf("unable to open the file\n");
		return -1;
	}
	lseek(fd,atoi(argv[2]),0);
	
	ret=read(fd,Arr,20);
	printf("Data From file is \n");
	write(1,Arr,ret);
	
	close(fd);
	return 0;
}