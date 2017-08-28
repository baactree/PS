// =====================================================================================
// 
//       Filename:  12995.cpp
//        Created:  2017년 08월 16일 18시 55분 48초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
int n, k;
ll dp[55][55];
ll ldp[55];
vector<int> adj[55];
void dfs(int now, int par){
	for(int i=0;i<adj[now].size();i++){
		int there=adj[now][i];
		if(there==par)
			continue;
		dfs(there, now);
	}
	dp[now][1]=1;
	for(int i=0;i<adj[now].size();i++){
		int there=adj[now][i];
		if(there==par)
			continue;
		memset(ldp, 0, sizeof(ldp));
		for(int i=2;i<=n;i++)
			for(int j=0;j<i;j++)
				ldp[i]=(ldp[i]+(dp[now][j]*dp[there][i-j])%mod)%mod;
		for(int i=2;i<=n;i++)
			dp[now][i]=(dp[now][i]+ldp[i])%mod;
	}
}
int main(){
	scanf("%d%d", &n, &k);
	for(int i=1;i<n;i++){
		int a, b;
		scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1, 0);
	int ans=0;
	for(int i=1;i<=n;i++)
		ans=(ans+dp[i][k])%mod;
	printf("%d\n", ans);
	return 0;
}

