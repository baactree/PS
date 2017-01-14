#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

typedef int LL;
int N;
LL arr[100000];
LL cache[100000][2];
// index부터 시작한 최대 연속합 
//0계속 뽑을꺼
//1그만 뽑을꺼 
LL search(int index,int mode)
{
	
	if(index==N)
		return 0;
	if(mode==1)
		return 0; 
	
	LL &ret=cache[index][mode];
	if(ret!=-(1e9*2))
		return ret;
	
	ret=search(index+1,0)+arr[index];
	ret=max(ret,search(index+1,1)+arr[index]);
	return ret;

}

int main()
{
//	freopen("sample.txt","r",stdin);
	cin>>N;
	for(int i=0;i<N;i++)
		scanf("%d",&arr[i]);
	for(int i=0;i<N;i++)
		for(int j=0;j<2;j++)
			cache[i][j]=-(1e9*2);
	LL ans=-(1e9*2);
	for(int i=N-1;i>=0;i--)
	{
		LL temp=search(i,0);
		if(ans<temp)
			ans=temp;
	}
	printf("%d\n",ans); 
//  while(true);
    return 0;
}
