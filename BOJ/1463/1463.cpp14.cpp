#include <iostream>
#include <stdio.h>


using namespace std;
 
int _min;
void search(int N,int cnt)
{
	if(_min<=cnt)
		return;
	if(N==1)
	{
		_min=min(_min,cnt);
		return;
	}
	if(N%3==0)
		search(N/3,cnt+1);
	if(N%2==0)
		search(N/2,cnt+1);
	search(N-1,cnt+1);
}
int main()
{
//	freopen("sample.txt","r",stdin);
	
	int N;
	cin>>N;
	_min=987654321;
	search(N,0);
	printf("%d\n",_min);
 //	while(true);
    return 0;
}
