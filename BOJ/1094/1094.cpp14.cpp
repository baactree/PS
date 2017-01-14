#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
typedef unsigned long long int LLU;
using namespace std;
 
int main()
{
	int N;
	int cnt=0;
	cin>>N;
	int div=64;
	while(true)
	{
		if(N==0)
			break;
		while(true)
		{
			if(N>=div)
			{
				N-=div;
				cnt++;
				break;
			}
			else
			{
				div>>=1;
			}
		}
	}
	printf("%d\n",cnt);
    return 0;
}
