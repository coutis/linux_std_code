#include"sigleton.h"

singleton* singleton::pSig = new singleton();


int main(int arg,char *args[])
{
	singleton*  s = singleton::Instance();
	if(s!=NULL)
	cout<<"complete"<<endl;
}
