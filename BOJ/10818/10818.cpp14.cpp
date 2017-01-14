#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
int N;
int dp[12];
int main()
{
	scanf("%d",&N);
	int input;
	int MIN=987654321;
	int MAX=-987654321;
	for(int i=0;i<N;i++)
	{
		scanf("%d",&input);
		MIN=min(MIN,input);
		MAX=max(MAX,input);
	}
	printf("%d %d\n",MIN,MAX);
	return 0;
}
