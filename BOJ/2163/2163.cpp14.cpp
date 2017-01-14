#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;

	printf("%d\n", a - 1 + (a*(b - 1)));

	return 0;
}
