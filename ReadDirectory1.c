# include<stdio.h>
# include<string.h>
# include<stdlib.h>
# include<fcntl.h>
# include<unistd.h>
# include<dirent.h>
# include<sys/stat.h>

int main(int argc ,char *argv[])
{
	 DIR *dp=NULL;
	char DirName[20];
	struct dirent *entry=NULL;
	char name[30];
	
	printf("please Enter the Directory name \n");
	scanf("%s",&DirName);
	
	dp=opendir(DirName);
	
	if(dp==NULL)
	{
		printf("Unable To open the Directory\n");
		return -1;
	}
	
	while((entry =readdir(dp)) !=NULL)
	{
		sprintf(name,"%s/%s",DirName,entry->d_name);
		printf("%s\n",name);
	}
	closedir(dp);
	
	return 0;
}
