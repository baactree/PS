#include "bits/stdc++.h"
using namespace std;
const int mod = 1000000;
int N;
int cache[1000][2][3];
int search(int idx, int late,int unab) {
	if (late == 2)
		return 0;
	if (unab == 3)
		return 0;
	if (idx == N)
		return 1;
	int &ret = cache[idx][late][unab];
	if (ret != -1)
		return ret;
	ret = search(idx+1, late, 0);
	ret = (ret+search(idx + 1, late + 1, 0))%mod;
	ret = (ret+search(idx + 1, late, unab + 1))%mod;
	return ret;
}
int main() {
	memset(cache, -1, sizeof(cache));
	cin >> N;
	printf("%d\n", search(0, 0, 0));
	return 0;
}