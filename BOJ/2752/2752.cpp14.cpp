#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int main()
{
//	freopen("sample.txt","r",stdin);
	int in[3];
	for(int i=0;i<3;i++)
		scanf("%d",&in[i]);
	sort(in,in+3);
	for(int i=0;i<3;i++)
		printf("%d ",in[i]);
	printf("\n");
//	while(true);
    return 0;
}
