#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cmath>
using namespace std;
int E,S,M;
int main()
{
//	freopen("sample.txt","r",stdin);
	cin>>E>>S>>M;
	for(int i=1;;i++)
	{
		if((((i-1)%15)+1==E)&&(((i-1)%28)+1==S)&&(((i-1)%19)+1==M))
		{
			printf("%d\n",i);
			break;
		}
	}


//  while(true);
    return 0;
}
