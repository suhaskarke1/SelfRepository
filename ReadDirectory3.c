# include<stdio.h>
# include<unistd.h>
# include<fcntl.h>
# include<dirent.h>
# include<sys/stat.h>
# include<stdlib.h>

int main(int argc,char *argv[])
{
	DIR *dp=NULL;
	char DirName[20];
	struct dirent *entry=NULL;
	char name[30];
	
	struct stat sobj;
	
	printf("please Enter the Directory name \n");
	scanf("%s",&DirName);
	
	dp=opendir(DirName);
	
	if(dp==NULL)
	{
		printf("Unable to Open The Dirctory \n");
		return -1;
	}
	
	while((entry =readdir(dp))!=NULL)
	{
		sprintf(name,"%s/%s",DirName,entry->d_name);
		stat(name,&sobj);
		if(S_ISREG(sobj.st_mode))
		{
		printf("File name : %s File Size : %ld \n",name,sobj.st_size);
		}
	
	}
	closedir(dp);
	
	return 0;
}