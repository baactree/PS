#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
using namespace std;
int output[9];
int main()
{
	int a,b,c;
	int sum;
	cin>>a>>b>>c;
	sum=a*b*c;
	while(sum)
	{
		output[sum%10]++;
		sum/=10;
	}
	for(int i=0;i<10;i++)
		printf("%d\n",output[i]);
	return 0;
}
