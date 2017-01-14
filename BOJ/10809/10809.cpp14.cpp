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
	memset(alpa,-1,sizeof(alpa));
	cin>>str;
	int len=strlen(str);
	for(int i=0;i<len;i++)
		if(alpa[str[i]-97]==-1)
		{
			alpa[str[i]-97]=i;
		}

	for(int i=0;i<26;i++)
		printf("%d ",alpa[i]);
	printf("\n");
//	while(true);
    return 0;
}
