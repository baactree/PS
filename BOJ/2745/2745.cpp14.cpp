#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>

using namespace std;
string str;
int main()
{
	int B;
	cin>>str>>B;
	int sum=0;
	int index=1;
	for(int i=str.length()-1;i>=0;i--)
	{
		if(str[i]>=65)
			sum+=(str[i]-55)*index;
		else
			sum+=(str[i]-48)*index;
		index*=B;
	}
	printf("%d\n",sum);
    return 0;
}
