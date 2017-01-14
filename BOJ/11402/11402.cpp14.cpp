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
LLU nCr[2001][2001];
vector<LLU> n;
vector<LLU> k;
int main() {
	LLU N, K, M;
	cin >> N >> K >> M;
	for (int i = 0; i < 2001; i++) {
		nCr[i][0] = 1;
		nCr[i][i] = 1;
		for (int j = 1; j <= i - 1; j++)
			nCr[i][j] = (nCr[i - 1][j - 1] + nCr[i - 1][j])%M;
	}
	while (N > 0 || K > 0) {
		n.push_back(N%M);
		k.push_back(K%M);
		N /= M;
		K /= M;
	}
	int size = n.size();
	LLU ans = 1;
	for (int i = 0; i < size; i++) {
		ans = (ans*nCr[n[i]][k[i]]) % M;
	}
	printf("%llu\n", ans);
	return 0;
}