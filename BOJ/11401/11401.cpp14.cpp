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
typedef unsigned long long int LLU;
#define X 1000000007

LLU F[4000001];
LLU IF[4000001];
LLU _pow(LLU a, LLU b) {
	if (b == 0)
		return 1;
	if (b == 1)
		return a;
	if (b % 2 == 0) {
		LLU temp = _pow(a, b / 2);
		return (temp*temp) % X;
	}
	return (_pow(a, b - 1)*a) % X;
}
int main() {
	int N, K;
	cin >> N >> K;
	F[0] = 1;
	for (int i = 1; i <= N; i++)
		F[i] = (F[i - 1] * i)%X;
	IF[N] = _pow(F[N], X - 2);
	for (int i = N - 1; i >= 0; i--)
		IF[i] = (IF[i + 1] * (i + 1)) % X;
	printf("%llu\n", ((F[N] * IF[K]) % X*IF[N - K]) % X);
	return 0;
}