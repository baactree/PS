// =====================================================================================
// 
//       Filename:  C.cpp
//        Created:  2017년 09월 24일 23시 47분 43초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m;
vector<int> adj[100005];
ll dp[100005][15][3];
ll tdp[15][3];
int k, x;
const int mod=1e9+7;
void dfs(int now, int par){
	for(int i=0;i<adj[now].size();i++){
		int there=adj[now][i];
		if(there!=par)
			dfs(there, now);
	}
	dp[now][0][0]=k-1;
	dp[now][1][1]=1;
	dp[now][0][2]=m-k;
	for(int i=0;i<adj[now].size();i++){
		int there=adj[now][i];
		if(there==par)
			continue;
		memset(tdp, 0, sizeof(tdp));
		for(int j=0;j<=x;j++)
			for(int t=0;t<=j;t++){
				tdp[j][0]+=(dp[now][t][0]*((dp[there][j-t][0]+
								dp[there][j-t][1]+dp[there][j-t][2])%mod))%mod;
				if(t>=1)
					tdp[j][1]+=(dp[now][t][1]*dp[there][j-t][0])%mod;
				tdp[j][2]+=(dp[now][t][2]*((dp[there][j-t][0]+dp[there][j-t][2])%mod))%mod;
				tdp[j][0]%=mod;
				tdp[j][1]%=mod;
				tdp[j][2]%=mod;
			}
		for(int j=0;j<=x;j++){
			for(int t=0;t<3;t++){
				dp[now][j][t]=tdp[j][t];
			}
		}
	}
}
int main(){
	scanf("%d%d", &n, &m);
	for(int i=0;i<n-1;i++){
		int a, b;
		scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	scanf("%d%d", &k, &x);
	dfs(1, 0);
	int ans=0;
	for(int i=0;i<=x;i++){
		for(int j=0;j<3;j++){
			ans=(ans+dp[1][i][j])%mod;
		}
	}
	printf("%d\n", ans);
	return 0;
}

