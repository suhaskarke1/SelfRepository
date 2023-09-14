# include<stdio.h>
# include<stdlib.h>
# include<string.h>
# include<unistd.h>
# include<fcntl.h>
# include<dirent.h>
# include<sys/stat.h>

int main(int argc ,char *argv[])
{
	DIR *dp=NULL;
	char DirName[20];
	struct dirent *entry =NULL;
	
	printf("Please enter the name of directory \n");
	scanf("%s",&DirName);
	
	dp=opendir(DirName);
	
	if(dp==NULL)
	{
		printf("Unable to open the directory \n");
		return -1;
	}
	else
	{
		printf("Directory is Successfully open \n");
		
	}
	closedir(dp);
	
	return 0;
}