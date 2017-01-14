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
double score[100000];
int N, K;
int main() {
	cin >> N >> K;
	for (int i = 0; i < N; i++)
		scanf("%lf", &score[i]);
	sort(score, score + N);
	double sum = 0;
	for (int i = K; i < N - K; i++)
		sum += score[i];
	double ans = sum;
	ans += score[K] * K;
	ans += score[N - K - 1] * K;
	printf("%.2lf\n%.2lf\n", (sum / (N - (2 * K)))+0.000001,ans/N+0.0000001);
	return 0;
}