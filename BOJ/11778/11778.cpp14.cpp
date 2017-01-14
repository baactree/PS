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
#define X 1000000007LLU
LLU a, b;
LLU fibo[2][2] = { {1,1},{1,0} };
LLU ans_a[2][2];
LLU ans_b[2][2];
LLU temp[2][2];
void multi(LLU A[][2], LLU B[][2], LLU C[][2]) {
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++) {
			LLU sum = 0;
			for (int k = 0; k < 2; k++)
				sum = (sum + (A[i][k] * B[k][j]) % X) % X;
			C[i][j] = sum;
		}
}
void pow(LLU t,LLU ans[][2]) {
	if (t == 0) {
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++)
				ans[i][j] = 1;
		return;
	}
	if (t == 1) {
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++)
				ans[i][j] = fibo[i][j];
		return;
	}
	if (t % 2 == 0) {
		pow(t / 2, ans);
		multi(ans, ans, temp);
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++)
				ans[i][j] = temp[i][j];
		return;
	}
	pow(t - 1, ans);
	multi(ans, fibo, temp);
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			ans[i][j] = temp[i][j];
	return;
}
LLU gcd(LLU a, LLU b) {
	if (b == 0)
		return a;
	return gcd(b, a%b);
}
int main() {
	LLU N,M;
	cin >> N>>M;
	LLU K = gcd(N, M);
	pow(K, ans_a);
	LLU n = ans_a[0][1];
	printf("%llu\n", n);
	return 0;
}