// =====================================================================================
// 
//       Filename:  2197.cpp
//        Created:  2017년 08월 16일 19시 19분 10초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> adj[155];
int dp[155][155];
int ldp[155];
void dfs(int now, int par){
	for(int i=0;i<adj[now].size();i++){
		int there=adj[now][i];
		if(there==par)
			continue;
		dfs(there, now);
	}
	dp[now][1]=0;
	dp[now][0]=1;
	for(int i=0;i<adj[now].size();i++){
		int there=adj[now][i];
		if(there==par)
			continue;
		memset(ldp, 0x3f, sizeof(ldp));	
		for(int i=1;i<=n;i++)
			for(int j=0;j<i;j++)
				ldp[i]=min(ldp[i], dp[now][i-j]+dp[there][j]);
		for(int i=1;i<=n;i++)
			dp[now][i]=ldp[i];
	}
}
int main(){
	memset(dp, 0x3f, sizeof(dp));
	scanf("%d%d", &n, &m);
	for(int i=1;i<n;i++){
		int a, b;
		scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1, 0);
	int ans=0x3f3f3f3f;
	for(int i=1;i<=n;i++)
		ans=min(ans, dp[i][m]+(i!=1));
	printf("%d\n", ans);
	return 0;
}

