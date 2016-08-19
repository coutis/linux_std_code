#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<errno.h>
#include"math.h"

int myatoi(const char *pStr)
{
	int bSign = 0;
  if(pStr[0]=='-')
	{
		bSign = 1;
		pStr++;
	}

	//计算长度
	int len = strlen(pStr);
  int temp =len;
	//数据转换
	int value = 0;
	for(int i=0;i<len;i++)
	{
    int t = pow(10,temp-1);
		temp--;
		t *= (pStr[i]-0x30);
		value += t;
	}

  if(bSign == 0)
		return value;
	else
		return (value*-1);

}

int main(int arg,char *args[])
{
	if(arg<2)
		return -1;
	
	int fd = open(args[1],O_RDWR);
	if(fd==-1)
		printf("%s",strerror(errno));
	else
	{
    char buf[100];
    memset(buf,0,sizeof(buf));
		while(read(fd,buf,sizeof(buf)-1)>0)
		{
			printf("%s\n",buf);
			memset(buf,0,sizeof(buf));
		}
		close(fd);
	}
	return EXIT_SUCCESS;
}
