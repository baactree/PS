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
typedef unsigned long long LLU;
int N;
int dp_max[2][3];
int dp_min[2][3];
int main() {
	cin >> N;
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	dp_max[0][0]=dp_min[0][0] = a;
	dp_max[0][1] = dp_min[0][1] = b;
	dp_max[0][2] = dp_min[0][2] = c;
	for (int i = 1; i < N; i++) {
		scanf("%d%d%d", &a, &b, &c);
		dp_max[i % 2][0] = dp_max[(i - 1) % 2][0]+ a;
		dp_max[i % 2][0] = max(dp_max[i % 2][0], dp_max[(i - 1) % 2][1] + a);
		dp_max[i % 2][1] = dp_max[(i - 1) % 2][0] + b;
		dp_max[i % 2][1] = max(dp_max[i % 2][1], dp_max[(i - 1) % 2][1] + b);
		dp_max[i % 2][1] = max(dp_max[i % 2][1], dp_max[(i - 1) % 2][2] + b);
		dp_max[i % 2][2] = dp_max[(i - 1) % 2][1] + c;
		dp_max[i % 2][2] = max(dp_max[i % 2][2], dp_max[(i - 1) % 2][2] + c);
			
		dp_min[i % 2][0] = dp_min[(i - 1) % 2][0] + a;
		dp_min[i % 2][0] = min(dp_min[i % 2][0], dp_min[(i - 1) % 2][1] + a);
		dp_min[i % 2][1] = dp_min[(i - 1) % 2][0] + b;
		dp_min[i % 2][1] = min(dp_min[i % 2][1], dp_min[(i - 1) % 2][1] + b);
		dp_min[i % 2][1] = min(dp_min[i % 2][1], dp_min[(i - 1) % 2][2] + b);
		dp_min[i % 2][2] = dp_min[(i - 1) % 2][1] + c;
		dp_min[i % 2][2] = min(dp_min[i % 2][2], dp_min[(i - 1) % 2][2] + c);
	}
	int Max, Min;
	int idx = (N - 1) % 2;
	Max = dp_max[idx][0];
	Max = max(Max, dp_max[idx][1]);
	Max = max(Max, dp_max[idx][2]);
	Min = dp_min[idx][0];
	Min = min(Min, dp_min[idx][1]);
	Min = min(Min, dp_min[idx][2]);
	printf("%d %d\n", Max, Min);
	return 0;
}