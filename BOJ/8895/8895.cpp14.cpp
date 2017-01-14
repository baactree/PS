#include "bits/stdc++.h"
using namespace std;
int N, L, R;
long long cache[21][21][21];
long long search(int idx, int left, int right) {
	if (idx == N&&left == L&&right == R)
		return 1;
	if (idx == N)
		return 0;
	long long &ret = cache[idx][left][right];
	if (ret != -1)
		return ret;
	ret = 0;
	if (left != L) 
		ret += search(idx + 1, left + 1, right);
	if (right != R)
		ret += search(idx + 1, left, right + 1);
	ret += search(idx + 1, left, right)*(idx - 1);
	return ret;
}
int main() {
	int Case;
	cin >> Case;
	while (Case--) {
		memset(cache, -1, sizeof(cache));
		scanf("%d%d%d", &N, &L, &R);
		printf("%lld\n", search(1, 1, 1));
	}
	return 0;
}