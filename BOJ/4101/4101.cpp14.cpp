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
	int a,b;
	while(true)
	{
		scanf("%d%d",&a,&b);
		if(a==0&&b==0)
			break;
		if(a>b)
			printf("Yes\n");
		else
			printf("No\n");	
			}
    return 0;
}
