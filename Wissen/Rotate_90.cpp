#include<iostream>
using namespace std;
#define M 3
int main()
{
	int arr[M][M]={
           1,2,3,
				   4,5,6,
				   7,8,9
				};	
        
	int temp[M][M];
	for(int i=0;i<=M-1;++i)   //20 = 22 21 = 12 22 = 02
	{
		for(int j =M-1;j>=0;j--)
		{
			temp[i][M-j-1]=arr[j][i];
		}
	}
	cout<<endl<<"After rotation"<<endl;
	for(int i=0;i<=M-1;++i)
	{
		for(int j =0;j<=M-1;++j)
		{
			cout<<temp[i][j]<<"  ";
		}
		cout<<endl;
	}
	getchar();
	return 0;
}
