#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
int main()
{
	int h,m,s;
	int input;
	scanf("%d%d%d%d",&h,&m,&s,&input);
	
	s+=input;
	m+=s/60;
	s%=60;
	h+=m/60;
	m%=60;
	h%=24;
	printf("%d %d %d\n",h,m,s);
	return 0;
}
