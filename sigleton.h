#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string>
#include<iostream>
using namespace std;

class singleton
{
	public:
		static singleton* Instance()
		{
			cout<<"has judge"<<endl;
			return pSig;
		}
    static void Destruct()
		{
			if(pSig!=NULL)
			{
				delete pSig;
				pSig = NULL;
			}
		}
	private:
		singleton()
		{
			cout<<"singleton construct "<<endl;
		}

		static singleton *pSig;
};
