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
#define X 10007
int nCr[1001][1001];
int search(int N, int K) {
	int &ret = nCr[N][K];
	if (ret != -1)
		return ret;
	if (K == 0 || N == K)
		return ret = 1;
	return ret = (search(N - 1, K - 1) + search(N - 1, K))%X;
}
int main() {
	memset(nCr, -1, sizeof(nCr));
	int N, K;
	cin >> N >> K;
	printf("%d\n", search(N, K));
	return 0;
}