#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>

int main(int arg,char *args[])
{
	if(arg<2)
		return 0;

/*	int fd = open(args[1],O_RDONLY);
	if(fd==-1)
		printf("%s\n",strerror(errno));

	else
	{
		struct stat _stat;
		fstat(fd,&_stat);
		if(S_ISREG(_stat.st_mode))
			printf("%s is a regular file\n",args[1]);
		if(S_ISDIR(_stat.st_mode))
			printf("%s is a directory file\n",args[1]);
	}
*/
/*  FILE* pf = fopen(args[1],"a+");
	if(pf)
	{
    char buf[100];
		memset(buf,0,sizeof(buf));
		int num = 0,temp = 0;
		while(temp = fread(buf,sizeof(char),100,pf))
		{
			num += temp;
			printf("%s\n",buf);
		  memset(buf,0,sizeof(buf));
		}
		printf("%d\n",num);

	}
	else
		printf("%s\n",strerror(errno));
  fclose(pf);*/


	return 1;
}
