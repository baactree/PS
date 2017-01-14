#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
int input[5];
int main()
{
	
	for(int i=0;i<5;i++)
		scanf("%d",&input[i]);
		
		int sum=0;
		for(int i=0;i<5;i++)
			sum+=input[i];
	sort(input,input+5);
	
	printf("%d\n%d\n",sum/5,input[2]);
	
	return 0;
}
