#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
int N;
int nidx[3000];
int iidx=1;
ll idxTree[3000 << 2];
ll idxTree_left[3000 << 2];
ll idxTree_right[3000 << 2];
ll idxTree_max[3000 << 2];
inline void init() {
	memset(idxTree, 0, sizeof(idxTree));
	memset(idxTree_left, 0, sizeof(idxTree_left));
	memset(idxTree_right, 0, sizeof(idxTree_right));
	memset(idxTree_max, 0, sizeof(idxTree_max));
}
inline void add(int pos, int val) {
	int cur = iidx + pos;
	idxTree[cur] += val;
	idxTree_left[cur] += val;
	idxTree_right[cur] += val;
	idxTree_max[cur] += val;
	cur >>= 1;
	while (cur > 0) {
		int l = cur * 2;
		int r = cur * 2 + 1;
		idxTree[cur] = idxTree[l] + idxTree[r];
		idxTree_left[cur] = max(idxTree_left[l], idxTree[l] + idxTree_left[r]);
		idxTree_right[cur] = max(idxTree_right[r], idxTree[r] + idxTree_right[l]);
		idxTree_max[cur] = max(max(idxTree_right[l] + idxTree_left[r], idxTree[cur]), max(idxTree_max[l], idxTree_max[r]));
		cur >>= 1;
	}
}
struct dat {
	int x, y, val;
};
dat arr[3000];
bool cmp(const dat &a, const dat &b) {
	if (a.x == b.x)
		return a.y < b.y;
	return a.x < b.x;
}
bool cmp2(const dat &a, const dat &b) {
	if (a.y == b.y)
		return a.x < b.x;
	return a.y < b.y;
}

int main() {
	cin >> N;
	while (iidx < N)
		iidx <<= 1;
	for (int i = 0; i < N; i++)
		scanf("%d%d%d", &arr[i].x, &arr[i].y, &arr[i].val);
	sort(arr, arr + N, cmp);
	int idx = 0;
	nidx[0] = idx;
	for (int i = 1; i < N; i++) {
		if (arr[i].x == arr[i - 1].x)
			nidx[i] = idx;
		else {
			idx++;
			nidx[i] = idx;
		}
	}
	for (int i = 0; i < N; i++)
		arr[i].x = nidx[i];
	sort(arr, arr + N, cmp2);
	int st = 0;
	ll ans = 0;
	for (int i = 0; i < N; i++) {
		if (i + 1 < N&&arr[i].y == arr[i + 1].y)
			continue;
		init();
		for (int j = i; j >= 0 ; j--) {
			add(arr[j].x, arr[j].val);
			if (j > 0&&arr[j].y == arr[j - 1].y)
				continue;
			ans = max(ans, idxTree_max[1]);
		}
	}
	printf("%lld\n", ans);
	return 0;
}