#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;
int N;
int A[1000];
int cache[1000][1001];
int search(int index,int upper)
{
	if(index==N)
		return 0;
	int& ret=cache[index][upper];
	if(ret!=-1)
		return ret;
	ret=0;
	if(A[index]>upper)
		ret=search(index+1,A[index])+1;
	
	ret=max(ret,search(index+1,upper));
	
	return ret;
}
int main()
{
//	freopen("sample.txt","r",stdin);
	
	cin>>N;
	memset(cache,-1,sizeof(cache));
	for(int i=0;i<N;i++)
		scanf("%d",&A[i]);
	
	printf("%d\n",search(0,0));
//  while(true);
    return 0;
}
