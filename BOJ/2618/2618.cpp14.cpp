#include "bits/stdc++.h"
using namespace std;
pair<int, int> le[1001], ri[1001];
int N, W;
int cache[1001][1001];
static inline int dist(const pair<int,int>& x, const pair<int,int>& y) {
	return abs(x.first - y.first) + abs(x.second - y.second);
}
int search(int left, int right) {
	int idx = max(left, right);
	if (idx==W)
		return 0;
	int &ret = cache[left][right];
	if (ret != -1)
		return ret;
	ret = search(idx + 1, right) + dist(le[idx+1], le[left]);
	ret = min(ret, search(left, idx + 1) + dist(ri[idx+1], ri[right]));
	return ret;
}
vector<int> ans;
void search_path(int left, int right) {
	int idx = max(left, right);
	if (idx == W)
		return;
	if (cache[idx + 1][right] + dist(le[idx + 1], le[left]) < cache[left][idx + 1] + dist(ri[idx + 1], ri[right])) {
		ans.push_back(1);
		search_path(idx + 1, right);
		return;
	}
	ans.push_back(2);
	search_path(left, idx + 1);
}
int main() {
	memset(cache, -1, sizeof(cache));
	cin >> N >> W;
	for (int i = 1; i <= W; i++) {
		scanf("%d%d", &le[i].first, &le[i].second);
		ri[i] = le[i];
	}
	le[0].first = le[0].second = 1;
	ri[0].first = ri[0].second = N;
	printf("%d\n", search(0, 0));
	search_path(0, 0);
	for (int i = 0; i < ans.size(); i++)
		printf("%d\n", ans[i]);
	return 0;
}