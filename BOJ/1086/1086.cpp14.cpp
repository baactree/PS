#include "bits/stdc++.h"
using namespace std;
string arr[15];
long long cache[1 << 15][100];
int mod[15];
int len[15];
int dcache[15000];
int N, K;
int g;
long long gcd(long long a, long long b) {
	return b ? gcd(b, a%b) : a;
}
long long fact(int n) {
	if (n == 1)
		return 1;
	return n*fact(n - 1);
}
int d_mod(int idx) {
	if (idx == 1)
		return 1;
	int &ret = dcache[idx];
	if (ret != -1)
		return ret;
	return ret=(10 * d_mod(idx - 1)) % K;
}
long long search(int state, int m) {
	if (state == (1<<N)-1) {
		if (m == 0)
			return 1;
		return 0;
	}
	long long &ret = cache[state][m];
	if (ret != -1)
		return ret;
	ret = 0ll;
	int l = 0;
	for (int i = 0; i < N; i++)
		if (state&(1 << i))
			l += len[i];
	l++;
	for (int i = 0; i < N;i++)
		if (!(state&(1 << i))) 
			ret += search(state | (1 << i), (m + mod[i] * d_mod(l)) % K);
	return ret;
}
int main() {
	memset(cache, -1, sizeof(cache));
	memset(dcache, -1, sizeof(dcache));
	scanf("%d", &N);
	for (int i = 0; i < N; i++) 
		cin >> arr[i];
	scanf("%d", &K);
	for (int i = 0; i < N; i++) {
		len[i] = arr[i].length();
		for (int j = 0; j < len[i]; j++) {
			mod[i] += (arr[i][j] - '0') * d_mod(len[i] - j);
			mod[i] %=K;
		}
	}
	long long p = search(0, 0);
	long long q = fact(N);
	long long k = gcd(p, q);
	printf("%lld/%lld\n", p / k, q / k);
	return 0;
}