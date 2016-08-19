#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

extern int add(int a,int b);

int main(int arg,char *args[])
{
	cout<<"input number is "<<arg<<endl;

	if(arg>2)
	{
		int a = atoi(args[1]);
		int b = atoi(args[2]);
		cout<<"a + b = "<<add(a,b)<<endl;
	}
	return 0;
}
