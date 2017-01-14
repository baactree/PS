#include "bits/stdc++.h"
using namespace std;
int N, D;
struct Edge {
	int st;
	int fi;
	int dis;
};
bool cmp(const Edge& a, const Edge& b) {
	if (a.st == b.st) {
		if (a.fi == b.fi)
			return a.dis < b.dis;
		return a.fi < b.fi;
	}
	return a.st < b.st;
}
vector<Edge> arr;
int dp[10001];
int main(){
	cin >> N >> D;
	int a, b, d;
	for (int i = 0; i < N; i++) {
		scanf("%d%d%d", &a, &b, &d);
		Edge temp;
		temp.st = a;
		temp.fi = b;
		temp.dis = d;
		arr.push_back(temp);
	}
	sort(arr.begin(), arr.end(), cmp);
	for (int i = 0; i <= D; i++)
		dp[i] = i;
	int idx = 0;
	for (int i = 0; i <= D; i++) {
		if (i != 0)
			dp[i] = min(dp[i], dp[i - 1] + 1);
		while (idx!=arr.size()&&arr[idx].st == i) {
			dp[arr[idx].fi] = min(dp[arr[idx].fi], dp[i] + arr[idx].dis);
			idx++;
		}
	}
	printf("%d\n", dp[D]);
	return 0;
}