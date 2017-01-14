#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <cmath>


using namespace std;

bool prime[1000001];
int main()
{
//	freopen("sample.txt","r",stdin);
	prime[1]=true;
	for(int i=2;i<10000;i++)
		if(!prime[i])
		{
			for(int j=i+i;j<=1000000;j+=i)
				prime[j]=true;
		}
	while(true)
	{
		int N;
		scanf("%d",&N);
		if(N==0)
			break;
		bool flag=true;
		for(int i=3;i<500000;i++)
		{
			if(!prime[i])
				if(!prime[N-i])
				{
					printf("%d = %d + %d\n",N,i,N-i);
					flag=false;
					break;
					
				}
		}
		if(flag)
			printf("Goldbach's conjecture is wrong.\n");
	}


//	while(true);
    return 0;
}
