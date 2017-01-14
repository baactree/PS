#include "bits/stdc++.h"
using namespace std;
int N;
int weight[10001];
vector<int> Map[10001];
bool trip[10001];
int cache[10001][2];
int search(int now, int par) {
	for (int i = 0; i < Map[now].size(); i++) {
		int there = Map[now][i];
		if (there != par)
			search(there, now);
	}
	cache[now][0] = 0;
	cache[now][1] = weight[now];
	for (int i = 0; i < Map[now].size(); i++) {
		int there = Map[now][i];
		if (there != par) {
			cache[now][0] += max(cache[there][0], cache[there][1]);
			cache[now][1] += cache[there][0];
		}
	}
	return max(cache[now][0], cache[now][1]);
}
vector<int> ans;
void search(int now, bool picked, int par) {
	if (picked) {
		ans.push_back(now);
		for (int i = 0; i < Map[now].size(); i++) {
			int there = Map[now][i];
			if (there != par)
				search(there, 0, now);
		}
		return;
	}
	for (int i = 0; i < Map[now].size(); i++) {
		int there = Map[now][i];
		if (there != par) {
			if (cache[there][0]>cache[there][1])
				search(there, 0, now);
			else
				search(there, 1, now);
		}
	}
}
int main() {
	memset(cache, -1, sizeof(cache));
	cin >> N;
	for (int i = 1; i <= N; i++)
		scanf("%d", &weight[i]);
	int a, b;
	for (int i = 1; i < N; i++) {
		scanf("%d%d", &a, &b);
		Map[a].push_back(b);
		Map[b].push_back(a);
	}
	Map[0].push_back(1);
	printf("%d\n",search(0, 0));
	search(0, 0, 0);
	for (int i = 0; i < ans.size(); i++)
		printf("%d ", ans[i]);
	printf("\n");
	return 0;
}