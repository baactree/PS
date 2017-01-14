#include "bits/stdc++.h"
using namespace std;
int N, M;
vector<int> Map[32001];
int cnt[32001];
int main() {
	scanf("%d%d", &N, &M);
	int a, b;
	for (int i = 0; i < M; i++) {
		scanf("%d%d", &a, &b);
		Map[a].push_back(b);
		cnt[b]++;
	}
	queue<int> q;
	for (int i = 1; i <= N; i++) 
		if (!cnt[i])
			q.push(i);
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		printf("%d ", now);
		for (int i = 0; i < Map[now].size(); i++) {
			cnt[Map[now][i]]--;
			if (!cnt[Map[now][i]])
				q.push(Map[now][i]);
		}
	}
	return 0;
}