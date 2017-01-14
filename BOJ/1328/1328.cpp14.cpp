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
#include <cmath>
using namespace std;
#define X 1000000007
typedef unsigned long long int LLU;
int N, L, R;
LLU cache[101][101][101];
LLU search(int n, int l, int r) {
	if (n == N&&l == L&&r == R)
		return 1;
	if (n == N)
		return 0;
	LLU &ret = cache[n][l][r];
	if (ret != -1)
		return ret;
	//왼쪽에 추가
	ret = search(n + 1, l + 1, r)%X;
	//오른쪽에 추가
	ret =(ret+ search(n + 1, l, r + 1)%X)%X;
	//사이에 추가
	ret =(ret+ (search(n + 1, l, r)%X*(n-1)%X)%X)%X;
	return ret%X;
}
int main() {
	memset(cache, -1, sizeof(cache));
	cin >> N >> L >> R;
	printf("%llu\n", search(1, 1, 1));
	return 0;
}