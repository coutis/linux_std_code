#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<errno.h>
#include<string.h>
#include<time.h>

void writelog(const char* log)
{
	time_t tDate;
	struct tm *eventTime;
	time(&tDate);
	eventTime = localtime(&tDate);

	int iYear = eventTime->tm_year+1900;
	int iMon = eventTime->tm_mon+1;
	int iDay = eventTime->tm_mday;
	int iHour = eventTime->tm_hour;
	int iMin = eventTime->tm_min;
	int iSec = eventTime->tm_sec;

	char sDate[16];
	sprintf(sDate,"%04d-%02d-%02d",iYear,iMon,iDay);
	char sTime[16];
	sprintf(sTime,"%04d-%02d-%02d",iHour,iMin,iSec);
	char s[1024];
	memset(s,0,sizeof(s));
	sprintf(s,"%s %s %s\n",sDate,sTime,log);

	FILE* pf = fopen("my.log","a+");
	if(pf == NULL)
		printf("write log my.log error:%s\n",strerror(errno));
  else
		fputs(s,pf);
	fclose(pf);
}


int main(int arg,char *args[])
{
   if(arg<2)
		 return -1;
	 else
     writelog(args[1]);
	 return 1;
}
