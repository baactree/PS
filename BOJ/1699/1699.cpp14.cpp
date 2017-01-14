#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cmath>
using namespace std;

int N;
int cache[100001];
int search(int n)
{
	if(n==0)
		return 0;
	int& ret=cache[n];
	if(ret!=-1)
		return ret;
	ret=987654321;
	int sq=sqrt(n);
	for(int i=1;i<=sq;i++)
		ret=min(ret,search(n-i*i)+1);
	
	return ret;
	
}
int main()
{
//	freopen("sample.txt","r",stdin);
	cin>>N;
	memset(cache,-1,sizeof(cache));
	printf("%d\n",search(N));
//  while(true);
    return 0;
}
