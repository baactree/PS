#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>


using namespace std;
//65 97
int main()
{
	int cnt=0;
	int ck,in;
	cin>>ck;
	for(int i=0;i<5;i++)
	{
		cin>>in;
		if(ck==in)
			cnt++;
	}
	printf("%d\n",cnt);
	return 0;
}
