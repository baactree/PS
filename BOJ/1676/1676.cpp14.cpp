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
char str[101];
int alpa[26];
int main()
{
//	freopen("sample.txt","r",stdin);
	int N;
	cin>>N;
	int cnt=0;
	for(int i=1;i<=N;i++)
	{
		int temp=i;
	while(true)
	{
		if(temp%5==0)
		{
			cnt++;
		}
		else
			break;
		temp/=5;
		
	}
}
	printf("%d\n",cnt);
    return 0;
}
