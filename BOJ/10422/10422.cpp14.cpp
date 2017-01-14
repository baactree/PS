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
#define X 1000000007
typedef unsigned long long int LLU;

LLU F[10001];
LLU IF[10001];
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
	F[0] = 1;
	for (int i = 1; i <= 10000; i++)
		F[i] = (F[i - 1] * i) % X;
	IF[10000] = _pow(F[10000], X - 2);
	for (int i = 1; i <= 10000; i++)
		IF[10000 - i] = (IF[10001 - i] * (10001 - i)) % X;
	int Case;
	cin >> Case;
	while (Case--) {
		int N;
		scanf("%d", &N);
		if (N % 2) {
			printf("0\n");
			continue;
		}
		N >>= 1;
		LLU ans = ((F[2*N]*IF[N])%X*IF[N+1])%X;
		printf("%llu\n",ans);
	}
	return 0;
}