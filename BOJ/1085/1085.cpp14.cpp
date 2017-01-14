#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
	int x, y, w, h;
	scanf("%d%d%d%d", &x, &y, &w, &h);
	int min;
	int minx,miny;
	minx = x > w - x ? w - x : x;
	miny = y > h - y ? h - y : y;
	min = minx > miny ? miny : minx;
	printf("%d\n",min);

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}
