#include <iostream>
#include <stdio.h>
#include <string.h>
#define X 10007
using namespace std;
int N;
int V[2][100000];
int cache[3][100000];
int search(int upper,int index)
{
	if(index==N)
		return 0;
	int& ret=cache[upper][index];
	if(ret!=-1)
		return ret;
	ret=0;
	
	if(upper==0)
	{
		ret=search(1,index+1)+V[1][index];
		ret=max(ret,search(2,index+1));
		return ret;
	}
	if(upper==1)
	{
		ret=search(0,index+1)+V[0][index];
		ret=max(ret,search(2,index+1));
		return ret;
	}
	if(upper==2)
	{
		ret=search(0,index+1)+V[0][index];
		ret=max(ret,search(1,index+1)+V[1][index]);
		ret=max(ret,search(2,index+1));
		return ret;
	}
	
	
}


int main()
{
//	freopen("sample.txt","r",stdin);
	int Case;
	cin>>Case;
	while(Case--)
	{
		memset(cache,-1,sizeof(cache));
		cin>>N;
		for(int i=0;i<2;i++)
			for(int j=0;j<N;j++)
				scanf("%d",&V[i][j]);
		
		
		printf("%d\n",search(2,0));
	}
 //   while(true);
    return 0;
}
