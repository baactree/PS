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
int chess[6]={1,1,2,2,2,8};
int main()
{
	int input;
	for(int i=0;i<6;i++)
	{
		scanf("%d",&input);
		printf("%d ",chess[i]-input);
	}
	printf("\n");
		
	//while(true);
    return 0;
}
