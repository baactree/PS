#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
	int N;
	cin >> N;
	int a, b;
	int cnt = 0;
	int temp=N;
	while (true)
	{

		a = temp / 10;
		b = temp % 10;
		cnt++;
		temp = b * 10 + (a + b) % 10;
		if (temp == N)
			break;
	}
	printf("%d\n", cnt);
	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}
