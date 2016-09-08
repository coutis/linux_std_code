#include<stdio.h>
#include<stdlib.h>


void Qsort(int *src,int start,int end)
{
  if(start>=end)
   return ;
  
  int temp = src[start];
  int t = 0;
  int _s = start,_e = end;
  while(_s<_e)
  {
    while(src[_e]>=temp) _e--;
	while(src[_s]<=temp) _s++;

	if(_s<_e)
	{
	  t = src[_e];
	  src[_e] = src[_s];
	  src[_s] = t;
	}
  }
  src[start] = src[_e];
  src[_e] = temp;

  Qsort(src,start,_e-1);
  Qsort(src,_e+1,end);
}

int main(int arg,char *args[])
{
   int a[] = {32,3,45,12,63,34,98,17};
   Qsort(a,0,7);
   for(int i=0;i<8;i++)
     printf("%d ",a[i]);
   printf("\n");
   return -1;
}
