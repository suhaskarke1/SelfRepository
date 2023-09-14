# include<stdio.h>
# include<stdlib.h>
# include<unistd.h>
# include<dirent.h>
# include<string.h>
# include<fcntl.h>
# include<sys/dir.h>

int main(int argc,char *argv[])
{
	DIR *dp=NULL;
	struct dirent *entry =NULL;
	char path[50]={'0'};
	
	dp=opendir(argv[1]);
	if(dp==NULL)
	{
		printf("Unable to Open The Dircetory\n");
		return -1;
	}
	while((entry=readdir(dp))!=NULL)
	{
		if(strcmp(argv[2],entry->d_name)==0)
		{
			printf("File is Present in Dircetory\n");
			sprintf(path,"%s/%s",argv[1],argv[2]);
			remove(path);
			printf("File is Succesfully Deleted \n");
			break;
		}
		
	}
	if(entry==NULL)
	{
		printf("There is no Such File in Dircetory\n");
		return -1;
	}
		
	
	return 0;
}