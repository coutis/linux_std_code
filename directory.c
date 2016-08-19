#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<dirent.h>
#include<string.h>
#include<errno.h>

int main(int arg,char *args[])
{
	if(arg<2)
		return 0;

	//打开指定路径
	DIR *dir = opendir(args[1]);
	if(dir)
		printf("%s\n",strerror(errno));

	struct dirent *pDirent = NULL;
	while(pDirent = readdir(dir))
	{
     printf("%s\n",pDirent->d_name);
	}

	closedir(dir);
}
