#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int MAX,input,output;
	MAX = 0;
	int now=0;
	for (int i = 0; i < 4; i++)
	{
		scanf("%d%d", &output, &input);
		now -= output;
		MAX = max(MAX, now);
		now += input;
		MAX = max(MAX, now);
	}
	printf("%d\n", MAX);
	return 0;	

}
