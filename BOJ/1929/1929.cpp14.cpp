#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>

using namespace std;
bool prime[1000001];
int main()
{
	int N,M;
	cin>>N>>M;
	prime[1]=true;
	for(int i=2;i<10000;i++)
		if(!prime[i])
		{
			for(int j=i+i;j<=1000000;j+=i)
				prime[j]=true;
		}
	
	
	for(int i=N;i<=M;i++)
		if(!prime[i])
			printf("%d\n",i);
	
//	while(true);
    return 0;
}
