#include<stdio.h>
#include "NCR.h"
//#include<iostream.h>
using namespace std;
int main()
{
	FILE *ptr_file;
    char buf[1000];

    ptr_file =fopen("input.txt","r");
    if (!ptr_file)
        return 1;
	NCRSample obj;
    while (fgets(buf,1000, ptr_file)!=NULL)
	{
		char * buffer = strtok(buf,"\n");
		obj.start(buffer);
	}
	cout<<endl<<"Total number of Duplicates and non-duplicate"<<endl;
	obj.getCountValidAndInvalid();
	cout<<endl<<"Most Frequent group"<<endl;
	obj.mostFrequentGroup();
	cout<<endl<<"Total Invalid sets "<<obj.getInvalidSize()<<endl;
	obj.getListOfInvalid();

	fclose(ptr_file);
 	getchar();
	return 0;
}
