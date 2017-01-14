#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a%b);
}
int main()
{
		
	int Case;
	scanf("%d", &Case);
	while (Case--)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		printf("%d\n",a/gcd(a,b)*b);
	}
	return 0;	

}
