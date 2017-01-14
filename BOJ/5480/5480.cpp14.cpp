#include "bits/stdc++.h"
using namespace std;
#define SIZE 100005
struct dat {
	int x1, y1, x2, y2, w;
};
dat ship[SIZE];
pair<int, int> query[SIZE];
bool broken[SIZE];
class idx_tree {
public:
	vector<vector<pair<int, int> > > tree;
	void init(int size) {
		tree.clear();
		tree.resize(size);
	}
	void input(int node, int node_left, int node_right, int left, int right, int idx) {
		if (right<node_left || left>node_right)
			return;
		if (left <= node_left&&node_right <= right) {
			tree[node].push_back({ idx, ship[idx].w });
			return;
		}
		int mid = (node_left + node_right) / 2;
		input(node * 2, node_left, mid, left, right, idx);
		input(node * 2 + 1, mid + 1, node_right, left, right, idx);
	}
	int search(int node, int node_left, int node_right, int idx) {
		int ret = 0;
		if (idx<node_left || idx>node_right)
			return ret;
		if (node_left <= idx&&idx <= node_right) {
			for (int i = 0; i < tree[node].size(); i++)
				if (!broken[tree[node][i].first]) {
					ret = max(ret, tree[node][i].second);
					broken[tree[node][i].first] = true;
				}
			tree[node].clear();
		}
		if (node_left == node_right)
			return ret;
		int mid = (node_left + node_right) / 2;
		ret = max(ret, search(node * 2, node_left, mid, idx));
		ret = max(ret, search(node * 2 + 1, mid + 1, node_right, idx));
		return ret;
	}
};
int N, K, L;
int xidx[SIZE * 3];
int yidx[SIZE * 3];
idx_tree x;
idx_tree y;
int main() {
	int Case;
	cin >> Case;
	while (Case--) {
		memset(broken, 0, sizeof(broken));
		scanf("%d%d%d", &N, &K, &L);
		int idx_x, idx_y;
		idx_x = idx_y = 0;
		for (int i = 0; i < K; i++) {
			scanf("%d%d%d%d%d", &ship[i].x1, &ship[i].y1, &ship[i].x2, &ship[i].y2, &ship[i].w);
			if (ship[i].x1 > ship[i].x2)
				swap(ship[i].x1, ship[i].x2);
			if (ship[i].y1 > ship[i].y2)
				swap(ship[i].y1, ship[i].y2);
			xidx[idx_x++] = ship[i].x1; xidx[idx_x++] = ship[i].x2;
			yidx[idx_y++] = ship[i].y1; yidx[idx_y++] = ship[i].y2;
		}
		for (int i = 0; i < L; i++) {
			scanf("%d%d", &query[i].first, &query[i].second);
			if (query[i].second)
				xidx[idx_x++] = query[i].first;
			else
				yidx[idx_y++] = query[i].first;
		}
		sort(xidx, xidx + idx_x);
		sort(yidx, yidx + idx_y);
		idx_x = unique(xidx, xidx + idx_x) - xidx;
		idx_y = unique(yidx, yidx + idx_y) - yidx;
		x.init(idx_x * 4);
		y.init(idx_y * 4);
		int a, b;
		for (int i = 0; i < K; i++) {
			a = lower_bound(xidx, xidx + idx_x, ship[i].x1) - xidx;
			b = lower_bound(xidx, xidx + idx_x, ship[i].x2) - xidx;
			x.input(1, 0, idx_x - 1, a, b, i);
			a = lower_bound(yidx, yidx + idx_y, ship[i].y1) - yidx;
			b = lower_bound(yidx, yidx + idx_y, ship[i].y2) - yidx;
			y.input(1, 0, idx_y - 1, a, b, i);
		}
		int idx;
		int ans;
		for (int i = 0; i < L; i++) {
			if (query[i].second) {
				idx = lower_bound(xidx, xidx + idx_x, query[i].first) - xidx;
				ans = x.search(1, 0, idx_x - 1, idx);
				printf("%d\n", ans);
			}
			else {
				idx = lower_bound(yidx, yidx + idx_y, query[i].first) - yidx;
				ans = y.search(1, 0, idx_y - 1, idx);
				printf("%d\n", ans);
			}
		}
	}
	return 0;
}
