#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int main()
{
	int Case=3;
	while(Case--)
	{
		int a=0;
		int input;
		for(int i=0;i<4;i++)
		{
			scanf("%d",&input);
			if(input)
			{
				a++;
			}
		}
		switch(a)
		{
			case 0:
				printf("D\n");
				break;
			case 1:
				printf("C\n");
				break;
			case 2:
				printf("B\n");
				break;
			case 3:
				printf("A\n");
				break;
			case 4:
				printf("E\n");
				break;
		}
	}
	return 0;
}
