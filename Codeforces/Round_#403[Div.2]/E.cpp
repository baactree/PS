// =====================================================================================
// 
//       Filename:  E.cpp
//        Created:  2017년 03월 31일 16시 11분 34초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;

int n, m, k;
vector<int> adj[200001];
bool trip[200001];
int pp;

int euler_tour[400000];
void dfs(int x) {
	trip[x] = true;
	euler_tour[pp++] = x;
	for (int i = 0; i < adj[x].size(); i++) {
		int there = adj[x][i];
		if (trip[there])
			continue;
		dfs(there);
		euler_tour[pp++] = x;
	}
	return;
}
int main(void) {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1);
	int sum = 2 * n - 1;
	int idx = 0;
	int p = ceil(2. * n / k);
	while (sum >= p) {
		k--;
		printf("%d ", p);
		int t = p;
		while (t--) 
			printf("%d ", euler_tour[idx++]);
		printf("\n");
		sum -= p;
	}
	if (sum != 0) {
		k--;
		printf("%d ", sum);
		for (int i = idx; i < 2 * n - 1; i++)
			printf("%d ", euler_tour[i]);
		printf("\n");
	}
	while (k--) {
		printf("1 1\n");
	}
	return 0;
}
