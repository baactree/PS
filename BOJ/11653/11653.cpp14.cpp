#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stdlib.h>
#include <cmath>
#include <deque>
using namespace std;
bool prime[3201];
int main()
{
	prime[1]=true;
	for(int i=2;i<60;i++)
		if(!prime[i])
		{
			for(int j=i+i;j<=3200;j+=i)
				prime[j]=true;
		}
		
		int N;
		cin>>N;
		int temp=sqrt(N);
	for(int i=1;i<=temp;i++)
	{
		if(!prime[i])
		{
			while(true)
			{
				if(N%i==0)
				{
					printf("%d\n",i);
					N/=i;
				}
				else
					break;
			}
		}
	}
		if(N!=1)
			printf("%d\n",N);
//	freopen("sample.txt","r",stdin);

// while(true);
    return 0;
}
