#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <map>
#include <utility>
#include <deque>
#include <stack>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;
int main() {
	int a, b;
	int Case;
	cin >> Case;
	while (Case--)
	{
		scanf("%d,%d", &a, &b);
		printf("%d\n", a + b);
	}
	return 0;
}