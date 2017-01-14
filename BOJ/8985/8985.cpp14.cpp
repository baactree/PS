#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
struct row_line {
	int y;
	int a, b;
};
row_line hori[150010];
row_line RMQ[500000];
int k[500010];
int h_s[500010];
int h_f[500010];
int N, K;
row_line init(int left, int right, int node) {
	if (left == right)
		return RMQ[node] = hori[left];
	int mid = (left + right) / 2;
	row_line leftMin = init(left, mid, node * 2);
	row_line rightMin = init(mid + 1, right, node * 2 + 1);
	if (leftMin.y < rightMin.y)
		RMQ[node] = leftMin;
	else
		RMQ[node] = rightMin;
	return RMQ[node];
}
row_line query(int left, int right, int node, int nodeLeft, int nodeRight) {
	row_line ret;
	ret.y = 0x7fffffff;
	if (right < nodeLeft || nodeRight < left)
		return ret;
	if (left <= nodeLeft&&nodeRight <= right)
		return RMQ[node];
	int mid = (nodeLeft + nodeRight) / 2;
	row_line temp;
	ret = query(left, right, node * 2, nodeLeft, mid);
	temp = query(left, right, node * 2 + 1, mid + 1, nodeRight);
	if (ret.y < temp.y)
		return ret;
	return temp;
}
ll ans_vol;
double search(int le, int ri, int ny) {
	double ret = 0;
	if (ri == le)
		return 0;
	int num = k[ri] - k[le];
	if (num == 0) {
		row_line temp = query(h_s[le], h_f[ri], 1, 0, N - 1);
		ll vol = (ll)(temp.y - (ll)ny)*(ri - le);
		ans_vol += vol;
		search(le, temp.a, temp.y);
		search(temp.b, ri, temp.y);
		return ret;
	}
	row_line temp = query(h_s[le], h_f[ri], 1, 0, N - 1);
	ll vol= (ll)(temp.y - (ll)ny)*(ri - le);
	ret = vol / (double)num;
	double t = search(le, temp.a, temp.y);
	double t2 = search(temp.b, ri, temp.y);
	ret += max(t, t2);
	return ret;
}
int main() {
	int a, b, c, d;
	scanf("%d%d%d", &N, &a, &b);
	N = (N / 2) - 1;
	for (int i = 0; i < N; i++) {
		scanf("%d%d%d%d", &a, &b, &c, &d);
		hori[i].y = b;
		hori[i].a = a;
		hori[i].b = c;
		h_s[a] = i;
		h_f[c] = i;
	}
	init(0, N - 1, 1);
	scanf("%d%d", &a, &b);
	int le, ri;
	le = 0; ri = a;
	cin >> K;
	int cnt = 0;
	for (int i = 0; i < K; i++) {
		scanf("%d%d%d%d", &a, &b, &c, &d);
		k[c] = 1;
	}
	for (int i = 1; i <= ri; i++) 
		k[i] += k[i - 1];
	double ans_tm = search(le, ri, 0);
	printf("%.2lf\n%lld\n", ans_tm, ans_vol);
	return 0;
}