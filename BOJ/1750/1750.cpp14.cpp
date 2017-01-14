/////////////////////////////////////////////////////
#ifdef _DEBUG
#include "bits_stdc++.h"
#else
#include "bits/stdc++.h"
#endif
using namespace std;
typedef pair<int, int> pii;
typedef vector<vector<pii > > Edge;
typedef unsigned long long llu;
typedef long long ll;
typedef priority_queue<pii > Pq;
typedef vector<int>::iterator It;
#define INF 0x3f3f3f3f
#define UINF 0xffffffffu
#define LINF 0x3f3f3f3f3f3f3f3fll
#define MOD 1000000007
#define EOD 1e-9
#define all(x) x.begin(),x.end()
const double PI = acos(0.0)*2.0;
/////////////////////////////////////////////////////
int N;
int arr[100];
int cache[100][100001];
const int mod = 10000003;
int gcd(int a, int b) {
	return b ? gcd(b, a%b) : a;
}
int solve(int idx, int num) {
	if (idx == N) {
		if (num == 1)
			return 1;
		return 0;
	}
	int &ret = cache[idx][num];
	if (ret != -1)
		return ret;
	ret = solve(idx + 1, num);
	ret += solve(idx + 1, gcd(arr[idx], num));
	ret %= mod;
	return ret;
}
int main() {
	memset(cache, -1, sizeof(cache));
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	printf("%d\n", solve(0, 0));
	return 0;
}