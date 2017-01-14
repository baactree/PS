#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>


using namespace std;
//65 97
int main()
{
	int N,K;
	cin>>N>>K;
	int cnt=0;
	int i;
	for(i=1;i<=N;i++)
	{
		if(N%i==0)
		{
			cnt++;
			if(cnt==K)
			{
				printf("%d\n",i);
				break;
			}
		}
	}
	if(i==N+1)
		printf("0\n");
	return 0;
}
