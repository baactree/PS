#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
#include <cmath>
using namespace std;

int trip[10000000];
int N;
int next(int n,int p)
{
	int sum=0;
	while(true)
	{
		sum+=pow((float)(n%10),p);
		n/=10;
		if(n==0)
			break;
	}
	return sum;
}
void search(int a,int p, int cnt)
{
	trip[a]=cnt;
	int b=next(a,p);
	if(trip[b]==-1)
		search(b,p,cnt+1);
	else
		printf("%d\n",trip[b]);
}
int main()
{

//	freopen("sample.txt","r",stdin);
	memset(trip,-1,sizeof(trip));
	int A,P;
	cin>>A>>P;
	search(A,P,0);
//	while(true);

    return 0;
}
