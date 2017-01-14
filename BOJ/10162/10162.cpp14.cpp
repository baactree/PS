#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;



int main()
{
//	freopen("sample.txt","r",stdin);
	int T;
	cin>>T;
	int time[3]={300,60,10};
	int count[3];
	memset(count,0,sizeof(count));
	if(T>=time[0])
	{
		count[0]=T/time[0];
		T%=time[0];	
	}
	if(T>=time[1])
	{
		count[1]=T/time[1];
		T%=time[1];
	}
	if(T>=time[2])
	{
		count[2]=T/time[2];
		T%=time[2];
	}
	
	if(T!=0)
		printf("-1\n");
	else
		printf("%d %d %d\n",count[0],count[1],count[2]);
//	while(true);
    return 0;
}
