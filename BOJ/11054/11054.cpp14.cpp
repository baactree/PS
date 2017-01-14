#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;
int N;
int A[1000];
int cache[1000][1002][2];
//1이 오름 0이 내림으로 해보자 
int search(int index,int upper,int mode)
{
	if(index==N)
		return 0;
	int& ret=cache[index][upper][mode];
	if(ret!=-1)
		return ret;
	ret=0;
	if(mode==1)
	{
		if(A[index]>upper)
		{
			ret=search(index+1,A[index],1)+1;
			ret=max(ret,search(index+1,A[index],0)+1);
		}
		
		ret=max(ret,search(index+1,upper,1));
		ret=max(ret,search(index+1,upper,0));
	}
	if(mode==0)
	{
		if(A[index]<upper)
			ret=search(index+1,A[index],0)+1;
		
		ret=max(ret,search(index+1,upper,0));
	}
	return ret;
}
int main()
{
//	freopen("sample.txt","r",stdin);
	
	cin>>N;
	memset(cache,-1,sizeof(cache));
	for(int i=0;i<N;i++)
		scanf("%d",&A[i]);
	
	printf("%d\n",max(search(0,0,1),search(0,1001,0)));
//  while(true);
    return 0;
}
