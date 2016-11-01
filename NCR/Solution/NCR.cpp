#include "NCR.h"
int NCRSample::cmp(const void * a,const void * b)
{
	return *(char *)a - *(char *)b;
}
int NCRSample::checkInteger(char ch)
{
	if((ch >= 97 && ch <= 122) || (ch >= 65 && ch <= 90))
    {
		return 0;
    }
    else if(ch >= 48 && ch <= 57)
    {
		return 1;
    }
    else
    {
		return 0;
    }
}

//Get List of Invalid Set 
void NCRSample::getListOfInvalid()
{
	cout<<endl<<"List Of Invalid Sets"<<endl;
	list<string>::iterator li=invalid.begin();
	for(;li!=invalid.end();++li)
		cout<<*li<<endl;
}
//Get Count of Duplicate and non-duplicate set
void NCRSample::getCountValidAndInvalid()
{
	int valid =0;int invalid =0;
	map<string,int>::iterator mi=minput.begin();
	for(;mi!=minput.end();++mi)
	{ 
		if(mi->second > 1)
			valid++;
		else
			invalid++;
	}
	cout<<endl<<"Total Duplicate count is "<<valid<<endl;
	cout<<endl<<"Total Non-Duplicate count is "<<invalid<<endl;
}
struct comparator {
 bool operator()(int i, int j) {
 return i < j;
 }
};
//Finding Most Duplicate Group
void NCRSample::mostFrequentGroup()
{ 
	cout<<endl<<"Most Frequent Grp is "<<endl;
	priority_queue<int, std::vector<int>, comparator> maxHeap;
	map<string,int>::iterator mi=minput.begin();
	for(;mi!=minput.end();++mi)
	{
		if(mi->second > 1)
			maxHeap.push(mi->second);
	}
	int result =0;
	if(!maxHeap.empty())
		result = maxHeap.top();
	
	mi=minput.begin();
	for(;mi!=minput.end();++mi)
	{
		if(mi->second == result)
			cout<<(mi->first)<<endl;
	}

}
//Utility Function to Sort elements
void NCRSample::sortedInsert(list<string> &s, string x)
{
	if (s.empty())
    {
		s.push_front(x); 
        return;
    }	
	string temp = s.front();
	if(atoi(temp.c_str())>atoi(x.c_str()))
    {
		s.push_front(x); 
        return;
    }
	s.pop_front();
    sortedInsert(s, x); 
	s.push_front(temp);
}
// Function to sort stack
void NCRSample::sortStack(list<string> &s)
{
	if (!s.empty())
    {
		string x = s.front();
		s.pop_front();
		sortStack(s);
        sortedInsert(s, x);
    }
} 
char * NCRSample::sortInput(char * str,int len)
{
   const char s[2] = ",";
   char *token;
   list<string> lis;
   token = strtok(str, s);   
   while( token != NULL ) 
   {
	  lis.push_front(token);
      token = strtok(NULL, s);
   }
   sortStack(lis);
   char * res = new char[len+1];
   memset(res,0,len+1);
   while(!lis.empty())
   {
	   string s = lis.front();
	   lis.pop_front();
	   strcat(res,s.c_str());
	   if(lis.size()>0)
		   strcat(res,",");
   }
   cout<<res<<endl;
   return res;
}
//Starting Point
void NCRSample::start(char *str)
{
		int j =0;
		if(checkInteger(*str))
		{
			char * cur = sortInput(str,strlen(str)+1);
			if(!minput[cur])
				minput[cur]=1;
			else
				minput[cur]+=1;
		}
		else
		{
			invalid.push_back(str);
		}
}
int NCRSample::getInvalidSize()
{
	return invalid.size();
}
