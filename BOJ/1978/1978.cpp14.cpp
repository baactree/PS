#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;
char str[101];
bool prime(int a)
{
	if(a==1)
		return false;
	if(a==2)
		return true;
	if(a%2==0)
		return false;
	for(int i=3;i<=sqrt(a);i++)
	{
		if(a%i==0)
			return false;
	}
	return true;
}
int main()
{
	int N;
	int cnt=0;
	int input;
	cin>>N;
	while(N--)
	{
		scanf("%d",&input);
		if(prime(input))
			cnt++;
	}
	printf("%d\n",cnt);
	return 0;
}
