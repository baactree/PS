#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>


using namespace std;
//65 97
int gcd(int a, int b)
{
	if(b==0)
		return a;
	return gcd(b,a%b);
}
int main()
{
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	int mot,son;
	mot=b*d;
	son=a*d+b*c;
	int k=gcd(mot,son);
	mot=mot/k;
	son/=k;
	printf("%d %d\n",son,mot);
	return 0;
}
