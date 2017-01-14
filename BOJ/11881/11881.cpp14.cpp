#include "bits/stdc++.h"
using namespace std;
#define mod 1000000007
typedef long long ll;
int cnt[100001];
int N;
ll cache[3][100001];
ll search(int sum, int idx) {
	if (sum == 3)
		return 1;
	if (idx > 100000)
		return 0;
	ll &ret = cache[sum][idx];
	if (ret != -1)
		return ret;
	ret = search(sum, idx + 1);
	if (cnt[idx] != 0)
		ret += (((search(sum + 1, idx + 1)*(ll)cnt[idx])%mod) * (ll)idx)%mod;
	return ret%mod;
}
int main() {
	memset(cache, -1, sizeof(cache));
	cin >> N;
	int in;
	for (int i = 0; i < N; i++) {
		scanf("%d", &in);
		cnt[in]++;
	}
	printf("%lld\n", search(0,1));
	return 0;
}