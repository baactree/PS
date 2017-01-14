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

int main()
{
	int in[3];
	cin>>in[0]>>in[1]>>in[2];
	int cnt[3];
	cnt[0]=cnt[1]=cnt[2]=0;
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			if(in[i]==in[j])
				cnt[i]++;
	
	int _max=0;
	for(int i=0;i<3;i++)
		_max=max(_max,cnt[i]);
	switch (_max)
	{
		case 3:
			printf("%d\n",10000+1000*in[0]);
			break;
		case 2:
			for(int i=0;i<3;i++)
				if(cnt[i]==2)
				{
					printf("%d\n",1000+100*in[i]);
					break;
				}
			break;
		case 1:
			int now=0;
			for(int i=0;i<3;i++)
				now=max(now,in[i]);
			printf("%d\n",100*now);
			break;
	}
	
	
    return 0;
}
