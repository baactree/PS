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
unsigned long long int fibo[1000000];
int main() {
	int Case;
	int N, M;
	cin >> Case;
	for (int tc = 1; tc <= Case; tc++) {
		scanf("%d%d", &N, &M);
		fibo[0] = 0;
		fibo[1] = 1;
		for (int i = 2;; i++) {
			if (i != 2 && fibo[0] == 0 && fibo[1] == 1) {
				printf("%d %d\n", N, i - 2);
				break;
			}
			fibo[2] =(fibo[0] + fibo[1])%M;
			fibo[0] = fibo[1];
			fibo[1] = fibo[2];
		}

	}
	return 0;
}