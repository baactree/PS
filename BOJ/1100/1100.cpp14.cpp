#include <stdio.h>
#include <iostream>
using namespace std;
char Map[8][9];
int main()
{
	for (int i = 0; i < 8; i++)
		scanf("%s", Map[i]);
	int cnt = 0;
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
		{
			if ((i + j) % 2 == 0 && Map[i][j] == 'F')
				cnt++;
		}
	printf("%d\n",cnt);
	return 0;	

}
