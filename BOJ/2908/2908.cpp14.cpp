#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <deque>
#include <queue>
#include <stack>
#include <utility>
#include <vector>


using namespace std;
int main() {
	int a, b;
	int c, d;
	cin >> a >> b;
	c = a % 10;
	a /= 10;
	c *= 10;
	c += a % 10;
	a /= 10;
	c *= 10;
	c += a % 10;

	d = b % 10;
	b /= 10;
	d *= 10;
	d += b % 10;
	b /= 10;
	d *= 10;
	d += b % 10;
	if (c > d)
		printf("%d\n", c);
	else
		printf("%d\n", d);
	return 0;
}