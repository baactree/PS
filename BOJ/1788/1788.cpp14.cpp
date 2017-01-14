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
#define X 1000000000
int N;
long long int fibo[3];
int main() {
	cin >> N;
	if (N > 0) {
		if (N == 1)
			printf("1\n%d\n", N);
		else {
			fibo[0] = 0;
			fibo[1] = 1;
			for (int i = 2; i <= N; i++) {
				fibo[2] = (fibo[0] + fibo[1])%X;
				fibo[0] = fibo[1];
				fibo[1] = fibo[2];
			}
			if (fibo[2] == 0)
				printf("0\n");
			else
				printf("1\n");
			printf("%d\n", fibo[2]);
		}
	}
	else if (N == 0) {
		printf("0\n0\n");
	}
	else {
		fibo[0] = 1;
		fibo[1] = 0;
		N = abs(N);
		for (int i = 1; i <= N; i++) {
			fibo[2] = (fibo[0] - fibo[1])%X;
			fibo[0] = fibo[1];
			fibo[1] = fibo[2];
		}
		if (fibo[2] < 0) {
			printf("-1\n");
		}
		else if (fibo[2]>0) {
			printf("1\n");
		}
		else
			printf("0\n");
		printf("%lld\n", abs(fibo[2]));
	}
	return 0;
}