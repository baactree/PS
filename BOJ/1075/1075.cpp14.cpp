#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
typedef unsigned long long int LLU;
using namespace std;
 
int main()
{
	int N,F;
	cin>>N>>F;
	N=N-(N%100);
	int cnt=0;
	while(true)
	{
		if((N+cnt)%F==0)
			break;
		cnt++;
	}
	
	if(cnt<10)
		printf("0%d\n",cnt);
	else
		printf("%d\n",cnt);
    return 0;
}
