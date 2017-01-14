#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>


using namespace std;
//65 97
char input[1000001];
int alpa[26];
int main()
{
	scanf("%s",input);
	int len=strlen(input);
	for(int i=0;i<len;i++)
	{
		if(input[i]>='A'&&input[i]<='Z')
			input[i]+=32;
		alpa[input[i]-97]++;
	}
	
	int Max=0;
	int m_i;
	for(int i=0;i<26;i++)
	{
		if(Max<alpa[i])
		{
			Max=alpa[i];
			m_i=i;
		}	
	}
	int cnt=0;
	for(int i=0;i<26;i++)
	{
		if(Max==alpa[i])
			cnt++;
	}
	if(cnt==1)
		printf("%c\n",(m_i+65));
	else
		printf("?\n");
	return 0;
}
