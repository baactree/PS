#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
	int grade;
	cin >> grade;
	if (grade >= 90)
	{
		printf("A\n");
	}
	else if (grade >= 80)
	{
		printf("B\n");
	}
	else if (grade >= 70)
	{
		printf("C\n");
	}
	else if (grade >= 60)
	{
		printf("D\n");
	}
	else
		printf("F\n");
	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}
