#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>


using namespace std;
//65 97
char str[51];
int main()
{
//	freopen("sample.txt","r",stdin);
	int Case;
	cin>>Case;
	while(Case--)
	{
		cin>>str;
		int check=0;
		bool flag=true;
		for(int i=0;i<strlen(str);i++)
		{
			if(str[i]=='(')
				check++;
			else
				check--;
			if(check<0)
				flag=false;
		}
		if(check!=0)
			flag=false;
		if(flag)
			printf("YES\n");
		else
			printf("NO\n");
	
	}
	return 0;
}
