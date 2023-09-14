# include<stdio.h>
# include<stdlib.h>
# include<fcntl.h>
# include<string.h>
# include<dirent.h>
# include<sys/stat.h>

int main(int argc ,char *argv[])
{
	DIR *dp=NULL;
	char DirName[20];
	struct dirent *entry=NULL;
	
	printf("please enter the Directory name \n");
	scanf("%s",&DirName);
	
	dp=opendir(DirName);
	
	if(dp==NULL)
	{
		printf("Unable to Open Directory \n");
		return -1;
	}
	
	while((entry=readdir(dp)) !=NULL)
	{
		printf("%s\n",entry->d_name);
	}
	closedir(dp);
	
	
	return 0;
}