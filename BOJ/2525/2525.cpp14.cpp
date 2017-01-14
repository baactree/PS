#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;


int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	int hour, min;
	min = (b + c) % 60;
	hour = (a + (b + c) / 60) % 24;
	printf("%d %d\n", hour, min);
	
}
