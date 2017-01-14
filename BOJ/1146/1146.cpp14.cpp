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
int cache[100][100][2];
const int mod = 1000000;
int solve(int le, int ri, int mode) {
	if (le+ri== 0)
		return 1;
	int &ret = cache[le][ri][mode];
	if (ret != -1)
		return ret;
	ret = 0;
	//v
	if (mode) {
		for (int i = 1; i <= ri; i++) {
			ret += solve( le + i - 1, ri - i, 0);
			ret %= mod;
		}
		return ret;
	}
	//^
	for (int i = 1; i <= le; i++) {
		ret += solve(i - 1, ri + le - i, 1);
		ret %= mod;
	}
	return ret;
	
}
int main(){
	memset(cache, -1, sizeof(cache));
	scanf("%d", &N);
	int ans = 0;
	if (N == 1) {
		printf("1\n");
		return 0;
	}
	for(int i=1;i<=N;i++)
		for (int j = 1; j <= N; j++) {
			if (i == j)
				continue;
			ans += solve(j - 1 - (i<j), N - j - (i>j), i > j);
			ans %= mod;
		}
	printf("%d\n", ans);
	return 0;
}