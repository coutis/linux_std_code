#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

//merge sort
void Merge(int *src,int* dest,int first,int mid,int last)
{
	int _s = first;
	int _e = mid;
	int i = first;
	while(_s<mid && _e<=last)
	{
	  if(src[_s]<src[_e])
	   dest[i] = src[_s++];
	  else
	   dest[i] = src[_e++];
	 
	 i++;
	}
    while(_s<mid)
	  dest[i] = src[_s++],i++;
    while(_e<=last)
	  dest[i] = src[_e++],i++;
    
	for(int j=first;j<i;j++)
	  src[j] = dest[j];

	for(int i=0;i<8;i++)
	  printf("%d ",src[i]);
	  printf("\n");
}

void MergeSort(int *src,int* dest,int first,int last)
{
   assert(src);
   if(first>=last)
     return;
   else
   {
	 int mid = (first+last)/2+1;
	 MergeSort(src,dest,first,mid-1);
	 MergeSort(src,dest,mid,last);

	 //sort
	 Merge(src,dest,first,mid,last);
   }
}


int main(int args,char *argv[])
{

    int a[] = {7,3,65,12,34,29,78,45};
	int b[8];
	MergeSort(a,b,0,7);
    for(int i=0;i<8;i++)
	  printf("%d ",a[i]);
	printf("\n");
	return 0;
}
