#include<iostream>
#include<list>
#include <queue>
#include<algorithm>
#include<map>
#include<string>
using namespace std;

#define max 3
class NCRSample
{
	list<string> invalid;
	map<string,int> minput;
	void sortedInsert(list<string> &s, string x);
	int cmp(const void * a,const void * b);
	int checkInteger(char ch);
	void sortStack(list<string> &s);
	char * sortInput(char * str,int len);
public:
	int getInvalidSize();
	void getListOfInvalid();
	void getCountValidAndInvalid();
	void mostFrequentGroup();
	void start(char *str);
};
