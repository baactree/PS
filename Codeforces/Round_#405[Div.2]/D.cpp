// =====================================================================================
// 
//       Filename:  D.cpp
//        Created:  2017년 03월 31일 16시 09분 16초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;

int n, k;
int cnt[200001][5];
int depth[200001];
int temp[5];
vector<int> adj[200001];
long long ans = 0;
void dfs1(int v, int par,int dep) {
	depth[dep]++;
	cnt[v][0] = 1;
	for (int i = 0; i < adj[v].size(); i++) {
		int there = adj[v][i];
		if (there == par)
			continue;
		dfs1(there, v,dep+1);
		for (int i = 0; i < k; i++) {
			cnt[v][(i + 1) % k] += cnt[there][i];
		}
	}
}
void dfs2(int v, int par,long long now) {
	ans += now;
	for (int i = 0; i < adj[v].size(); i++) {
		int there = adj[v][i];
		if (there == par)
			continue;
		long long next = now;
		next = next - cnt[there][0] + (cnt[v][0] - cnt[there][k-1] + temp[0]);
		int tt[5];
		for (int i = 0; i < k; i++)
			tt[i] = temp[i];
		for(int i=0;i<k;i++)
			temp[(i+1)%k] = cnt[v][i] - cnt[there][(i+k-1)%k] + tt[i]; 
		dfs2(there,v, next);
		for (int i = 0; i < k; i++)
			temp[i] = tt[i];
	}
}
int main() {
	scanf("%d%d", &n,&k);
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs1(1, 0,0);
	long long st=0;
	for (int i = 0; i <= n; i++)
		st += (i+k-1)/k*depth[i];
	dfs2(1, 0, st);
	printf("%lld\n", ans/2);
	return 0;
}
