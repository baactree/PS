#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

int main()
{
	
	
	char str_j[1000];
	char str_d[1000];
	scanf("%s%s",str_j,str_d);
	if(strlen(str_j)>=strlen(str_d))
		printf("go\n");
	else
		printf("no\n");
	return 0;
}
