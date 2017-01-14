#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cmath>
using namespace std;

#define X 1000000000

int N,K;
int cache[201][201];

int search(int n,int k)
{
	
	int& ret=cache[n][k];

	if(n==0&&k==0)
		return ret=1;
	if(k==0)
		return ret=0;
	if(ret!=-1)
		return ret;
	
	ret=0;
	for(int i=0;i<=n;i++)
		ret=(ret+search(n-i,k-1))%X;
	
	return ret;
	
}

int main()
{
//	freopen("sample.txt","r",stdin);
	memset(cache,-1,sizeof(cache));
	cin>>N>>K;
	printf("%d\n",search(N,K));
//  while(true);
    return 0;
}
