# include<stdio.h>
# include<unistd.h>
# include<fcntl.h>
# include<dirent.h>
# include<stdlib.h>
# include<string.h>
# include<sys/stat.h>

# pragma pack(1)
struct FileInfo
{
	char FileName[20];
	int FileSize;
};
int main(int argc,char *argv[])
{
	DIR *dp=NULL;
	char DirName[20];
	struct dirent *entry=NULL;
	char name[30];
	struct stat sobj;
	struct FileInfo fobj;
	int fd=0;
	
	printf("please enter the Directory name \n");
	scanf("%s",&DirName);
	
	dp=opendir(DirName);
	if(dp==NULL)
	{
		printf("Unable to open Directory \n");
		return -1;
	}
	
	fd=creat("FileCombine.txt",0777);
	
	while((entry=readdir(dp))!=NULL)
	{
		sprintf(name,"%s/%s",DirName,entry->d_name);
		stat(name,&sobj);
		
		if(S_ISREG(sobj.st_mode))
		{
			fobj.FileSize=sobj.st_size;
			strcpy(fobj.FileName,entry->d_name);
			write(fd,&fobj,sizeof(fobj));
			printf("%s\n",entry->d_name);
		}
	}
	
	closedir(dp);
	
	return 0;
}