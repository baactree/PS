#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>

using namespace std;
int store[100000];
int main()
{
	int N,B;
	cin>>N>>B;
	int index=0;
	while(true)
	{
		store[index++]=N%B;
		N/=B;
		if(N==0)
			break;
			
	}
	for(int i=index-1;i>=0;i--)
	if(store[i]>=10)
		printf("%c",store[i]+55);
	else
		printf("%d",store[i]);
	printf("\n");
	
    return 0;
}
