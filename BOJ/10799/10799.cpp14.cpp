#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>


using namespace std;
//65 97
char str[100001];
int _count[100000];
int main()
{
//	freopen("sample.txt","r",stdin);
	cin>>str;
	int sum=0;
	int _idx=0;
	for(int i=0;i<strlen(str);i++)
	{
		if(str[i]=='(')
		{
			_count[_idx++]=i;
		}
		else
		{
			if(_count[_idx-1]+1==i)
			{
				_idx--;
				sum+=_idx;
			}
			else
			{
				_idx--;
				sum++;
			}
		}
		
	}
	printf("%d\n",sum);
//	while(true);
	return 0;
}
