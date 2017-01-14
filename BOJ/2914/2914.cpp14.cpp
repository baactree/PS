#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
char str[101];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	printf("%d\n",a*(b-1)+1);
	return 0;
}
