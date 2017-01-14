#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stdlib.h>
#include <cmath>
#include <deque>

using namespace std;
string str;
int main()
{
//	freopen("sample.txt","r",stdin);

	getline(cin,str);
	int len=str.length();
	for(int i=0;i<len;i++)
	{
		if(str[i]>='A'&&str[i]<='Z')
		{
			str[i]=((str[i]-65)+13)%26+65;
		}
		else if(str[i]>='a'&&str[i]<='z')
		{
			str[i]=((str[i]-97)+13)%26+97;
			
		}
	}
	cout<<str<<'\n';
    return 0;
}
