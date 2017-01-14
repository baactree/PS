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
int main()
{
	//freopen("sample.txt","r",stdin);
	int L,s,n,b;
	while(cin.getline(str,101))
	{
		L=s=n=b=0;
		int len=strlen(str);
		if(len==0)
			break;
		for(int i=0;i<len;i++)
			if(str[i]>='A'&&str[i]<='Z')
				L++;
			else if(str[i]>='a'&&str[i]<='z')
				s++;
			else if(str[i]>='0'&&str[i]<='9')
				n++;
			else if(str[i]==' ')
				b++;
			
		printf("%d %d %d %d\n",s,L,n,b);
	}
    return 0;
}
