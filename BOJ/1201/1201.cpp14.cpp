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
int ans[500];
int N, M, K;
//n남은 갯수,m남은 그룹
int length(int n, int m) {
	for (int i = K; i > 0; i--) {
		if (n - i >= m - 1)
			return i;
	}
}
int main() {
	int idx = 0;
	scanf("%d%d%d", &N, &M, &K);
	if (N >= M + K - 1 && N <= M*K) {
		int n, m;
		n = N;
		m = M;
		//적절한 분할
		while (m >= 0) {
			int x = length(n, m);
			n -= x;
			m--;
			int temp = idx + x;
			for (int i = 0; i < x; i++) {
				ans[idx++] = temp--;
			}
		}
		//적절한 출력
		for (int i = 0; i < N; i++)
			printf("%d ", ans[i]);
		printf("\n");
	}
	else {
		printf("-1\n");
	}
	return 0;
}