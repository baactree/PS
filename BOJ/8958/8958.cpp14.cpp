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

char input[81];
int main()
{
//	freopen("sample.txt","r",stdin);
	int N;
	cin>>N;
	for(int i=0;i<N;i++)
	{
		scanf("%s",input);
	int begin=0;
	int len=strlen(input);
	int sum=0;
	for(int i=0;i<len;i++)
		if(input[i]=='O')
		{
			sum+=begin+1;
			begin++;
		}
		else
			begin=0;
			
			printf("%d\n",sum);
		}
//	while(true);
    return 0;
}
