#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stdlib.h>
using namespace std;

int main()
{
//	freopen("sample.txt","r",stdin);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	a+=b;
	c+=d;
	long long int A,B;
	A=B=0;
	for(int i=0;i<a.length();i++)
	{
		A+=a[i]-48;
		A*=10;
	}
	A/=10;
	for(int i=0;i<c.length();i++)
	{
		B+=c[i]-48;
		B*=10;
	}
	B/=10;
	printf("%lld\n",A+B);
    return 0;
}
