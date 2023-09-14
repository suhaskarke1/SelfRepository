# include<stdio.h>
# include<stdlib.h>
# include<unistd.h>
# include<fcntl.h>
# include<dirent.h>
# include<string.h>
# include<sys/stat.h>

int main(int argc, char *argv[])
{
	DIR *dp=NULL;
	char DirName[20];
	char name[30];
	struct dirent *entry =NULL;
	char namecopy[30]={'\0'};
	struct stat sobj;
	int iMax=0;
	
	printf("Please enter the Directory Name \n");
	scanf("%s",&DirName);
	
	dp=opendir(DirName);
	if(dp==NULL)
	{
		printf("Unable to open the Directory \n");
		return -1;
	}
	
	while((entry =readdir(dp))!=NULL)
	{
		sprintf(name,"%s/%s",DirName,entry->d_name);
		stat(name,&sobj);
		if(S_ISREG(sobj.st_mode))
		{
			if(iMax<sobj.st_size)
			{
				iMax=sobj.st_size;
				strcpy(namecopy,name);
			}
		}
	}
	printf("Name of Largest file : %s with Size %d bytes \n",namecopy,iMax);
	
closedir(dp);
	
	
	return 0;
}