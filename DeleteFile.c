# include<stdio.h>
# include<unistd.h>
# include<stdlib.h>
# include<fcntl.h>
# include<dirent.h>
# include<string.h>
# include<sys/stat.h>

int main(int argc,char *argv[])
{
	DIR *dp=NULL;
	char DirName[20];
	struct dirent *entry=NULL;
	struct stat sobj;
	char name[30];
	
	printf("Please enter the Directory Name \n");
	scanf("%s",&DirName);
	
	dp=opendir(DirName);
	
	if(dp==NULL)
	{
		printf("Unable to open the Directory \n");
		return -1;
	}
	
	while((entry=readdir(dp))!=NULL)
	{
		sprintf(name,"%s/%s",DirName,entry->d_name);
		stat(name,&sobj);
			if(S_ISREG(sobj.st_mode))
			{
				if(sobj.st_size==0)
				{
					remove(name);
				}
			}
	}
	printf("File is Successfully Deleted\n");
	closedir(dp);
	
	return 0;
}