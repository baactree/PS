#include "bits/stdc++.h"
using namespace std;
int N;
vector<int> Map[501];
int node[501];
int ans[501];
int cnt[501];
int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &node[i]);
		while (true) {
			int in;
			scanf("%d", &in);
			if (in == -1)
				break;
			Map[in].push_back(i);
			cnt[i]++;
		}
		
	}
	queue<int> q;
	for (int i = 1; i <= N; i++)
		if (!cnt[i])
			q.push(i);
	int ret = 0;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 0; i < Map[now].size(); i++) {
			int there = Map[now][i];
			cnt[there]--;
			ans[there] = max(ans[there], ans[now] + node[now]);
			if (!cnt[there])
				q.push(there);
		}
	}
	for (int i = 1; i <= N; i++)
		printf("%d\n", ans[i] + node[i]);
	return 0;
}