// =====================================================================================
// 
//       Filename:  B.cpp
//        Created:  2017년 03월 31일 16시 08분 38초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> adj[150001];
int g[150001];
bool trip[150001];
int k[150001];
int dfs(int v,int cnt) {
	trip[v] = true;
	g[v] = cnt;
	int ret = 1;
	for (int i = 0; i < adj[v].size(); i++) {
		int there = adj[v][i];
		if (trip[there])
			continue;
		ret += dfs(there,cnt);
	}
	return ret;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (!trip[i]) {
			int count=dfs(i,cnt);
			k[cnt] = count;
			cnt++;
		}
	}
	bool flag = false;
	for (int i = 1; i <= n; i++) {
		if (k[g[i]] - 1 != adj[i].size())
			flag = true;
	}
	printf("%s\n", flag ? "NO" : "YES");
	return 0;
}
