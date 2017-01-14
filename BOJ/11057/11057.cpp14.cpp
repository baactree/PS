#include <iostream>
#include <stdio.h>
#include <string.h>
#define X 10007
using namespace std;
int N;
int cnt=0;
int cache[1000][10];
int search(int index, int upper)
{
	if(index==N)
		return 1;
	int& ret=cache[index][upper];
	if(ret!=-1)
		return ret;

	ret=0;
	for(int i=upper;i<10;i++)
		ret=(ret+search(index+1,i))%X;
		
	return ret;
}

int main()
{
//	freopen("sample.txt","r",stdin);
	cin>>N;
	memset(cache,-1,sizeof(cache));
	printf("%d\n",search(0,0));
 //   while(true);
    return 0;
}
