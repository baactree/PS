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

int main()
{
	string str;
	cin>>str;
	int len=str.length();
	for(int i=0;i<len;i++)
		if(str[i]>='A'&&str[i]<='Z')
			printf("%c",str[i]);
	printf("\n");
    return 0;
}
