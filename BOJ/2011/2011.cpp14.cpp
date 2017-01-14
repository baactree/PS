#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cmath>
using namespace std;

#define X 1000000

char N[5001];
int cache[5001];
int len;
int search(int index)
{
	if(index>len)
		return 0;
	
	int& ret=cache[index];
	
	if(ret!=-1)
		return ret;
	if(index==len)
		return ret=1;
	
	ret=0;
	if(N[index]>='1'&&N[index]<='26')
	{
		ret=(ret+search(index+1))%X;
		if(index+1<len)
			if((N[index]-48)*10+N[index+1]-48<27)
				ret=(ret+search(index+2))%X;
				
		return ret;
	}
	return ret;
		
	
}
int main()
{
//	freopen("sample.txt","r",stdin);
	memset(cache,-1,sizeof(cache));
	scanf("%s",N);
	len=strlen(N);
	int ans=search(0);
	printf("%d\n",ans);
//  while(true);
    return 0;
}
