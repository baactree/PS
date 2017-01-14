/////////////////////////////////////////////////////
#include "bits/stdc++.h"
using namespace std;
typedef pair<int, int> pii;
typedef vector<vector<pii > > Edge;
typedef unsigned long long llu;
typedef long long ll;
typedef priority_queue<pii > Pq;
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fll
#define MOD 1000000007
const double PI = acos(0.0)*2.0;
/////////////////////////////////////////////////////
int T, N;
pii arr[100];
int cache[10001][100];
int search(int t, int idx) {
	if (t > T)
		return 0;
	if (idx == N) {
		if (t == T)
			return 1;
		return 0;
	}
	int &ret = cache[t][idx];
	if (ret != -1)
		return ret;
	ret = 0;
	int k = 0;
	while (true) {
		if (k*arr[idx].second + t > T||k>arr[idx].first)
			break;
		ret += search(t + k*arr[idx].second, idx + 1);
		k++;
	}
	return ret;
}
int main() {
	memset(cache, -1, sizeof(cache));
	scanf("%d%d", &T, &N);
	for (int i = 0; i < N; i++) {
		scanf("%d%d", &arr[i].second, &arr[i].first);
	}
	printf("%d\n", search(0, 0));
	return 0;
}