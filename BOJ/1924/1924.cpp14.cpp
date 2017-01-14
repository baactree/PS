#include <stdio.h>
#include <iostream>

using namespace std;
int sum[13] = { 0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334 };
int main()
{
	
	int M, D;
	int y_d;
	cin >> M >> D;
	y_d = sum[M] + D;
	switch (y_d % 7)
	{
	case 1: printf("MON\n");
		break;
	case 2: printf("TUE\n");
		break;
	case 3: printf("WED\n");
		break;
	case 4: printf("THU\n");
		break;
	case 5: printf("FRI\n");
		break;
	case 6: printf("SAT\n");
		break;
	case 0: printf("SUN\n"); 
		break;

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}
