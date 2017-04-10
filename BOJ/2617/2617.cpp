// =====================================================================================
// 
//       Filename:  2617.cpp
//        Created:  2017년 04월 10일 18시 51분 01초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m;
int adj[100][100];
int trip[100];
int dfs(int now, int type) {
	int ret = 1;
	trip[now] = true;
	for (int i = 1; i <= n; i++) {
		int edge = type == 1 ? adj[now][i] : adj[i][now];
		if (!edge||trip[i])
			continue;
		ret += dfs(i, type);
	}
	return ret;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		adj[a][b] = 1;
	}
	int cnt = (n + 1) / 2;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		memset(trip, 0, sizeof(trip));
		if (dfs(i, 1)-1 >= cnt)
			ans++;
		else {
			memset(trip, 0, sizeof(trip));
			if (dfs(i, 2) -1>= cnt)
				ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}
