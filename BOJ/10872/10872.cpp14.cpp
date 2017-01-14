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
typedef unsigned long long ULL;
using namespace std;
ULL fact(ULL num)
{
	if(num==0)
		return 1;
	if(num==1)
		return 1;
	return fact(num-1)*num;
}
int main()
{
//	freopen("sample.txt","r",stdin);
	
	ULL input;
	cin>>input;
	printf("%d\n",fact(input));
    return 0;
}
