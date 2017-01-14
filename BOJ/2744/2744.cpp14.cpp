#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
char str[101];
int main()
{
	scanf("%s",str);
	int stre=strlen(str);
	for(int i=0;i<stre;i++)
		if(str[i]>='a'&&str[i]<='z')
			str[i]-=32;
		else
			str[i]+=32;
	printf("%s\n",str);
	return 0;
}
