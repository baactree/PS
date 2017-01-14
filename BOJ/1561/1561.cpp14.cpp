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
using namespace std;
typedef unsigned long long LLU;
LLU N, M;
LLU _runtime[10000];
LLU search(LLU data) {
	LLU sum = 0;
	for (LLU i = 0; i < M; i++) {
		sum += data/_runtime[i] ;
		if (data%_runtime[i] != 0LLU)
			sum++;
	}
	sum++;
	return sum;
}

int main() {
	cin >> N >> M;
	for (LLU i = 0; i < M; i++)
		scanf("%llu", &_runtime[i]);
	if (N > M) {
		LLU ans = 0;
		LLU r, l, mid;
		r = 0xfffffffffffffff0LLU;
		l = 1;
		while (r >= l) {
			mid = (r + l) / 2;
			LLU temp = search(mid);
			if (temp <= N) {
				ans = max(ans, mid);
				l = mid + 1;
			}
			else
				r = mid - 1;
		}
		LLU idx = search(ans);
		idx--;
		for (LLU i = 0; i  < M; i++) {
			if (ans%_runtime[i] == 0) {
				idx++;
				if (idx == N) {
					printf("%llu\n", i + 1LLU);
					break;
				}
			}
		}
	}
	else
		printf("%d\n", N);
	return 0;
}