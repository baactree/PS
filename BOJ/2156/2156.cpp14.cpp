#include <iostream>
#include <stdio.h>
#include <string.h>
#define X 10007
using namespace std;
int N;
int vol[10000];
int cache[10000][3];
int search(int index,int cnt)
{
	if(index==N)
		return 0;
	
	int& ret=cache[index][cnt];
	
	if(ret!=-1)
		return ret;
	ret=0;
	
	if(cnt!=2)
		ret=search(index+1,cnt+1)+vol[index];
	ret=max(ret,search(index+1,0));
	return ret;
}
int main()
{
//	freopen("sample.txt","r",stdin);

	cin>>N;
	memset(cache,-1,sizeof(cache));
	for(int i=0;i<N;i++)
		scanf("%d",&vol[i]);
	printf("%d\n",search(0,0));
 //   while(true);
    return 0;
}
