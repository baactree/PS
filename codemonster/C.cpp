// =====================================================================================
// 
//       Filename:  C.cpp
//        Created:  2017년 09월 29일 13시 04분 51초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
const int maxn=300005;
int n, k;
vector<int> adj[maxn];
int col[maxn];
int cnt[maxn];
int dp[maxn][3];
int tdp[3];
const int mod=1e9+7;
typedef long long ll;
void dfs(int now, int par){
	cnt[now]=col[now];
	for(int i=0;i<adj[now].size();i++){
		int there=adj[now][i];
		if(there==par)
			continue;
		dfs(there, now);
		cnt[now]+=cnt[there];
	}
	if(k==1){
		if(col[now])
			dp[now][2]=1;
		else
			dp[now][0]=1;
	}
	else
		dp[now][col[now]]=1;
	int ns=col[now];
	for(int i=0;i<adj[now].size();i++){
		int there=adj[now][i];
		if(there==par)
			continue;
		memset(tdp, 0, sizeof(tdp));	
		// 0, 0
		tdp[0]+=((ll)dp[now][0]*dp[there][0])%mod;
		tdp[0]%=mod;
		// 0, 1
		tdp[1]+=((ll)dp[now][0]*dp[there][1])%mod;
		tdp[1]%=mod;
		// 0, 2
		tdp[2]+=((ll)dp[now][0]*dp[there][2])%mod;
		tdp[2]%=mod;
		// 1, 0
		tdp[1]+=((ll)dp[now][1]*dp[there][0])%mod;
		tdp[1]%=mod;
		// 1, 1
		if(ns%k!=0&&cnt[there]%k!=0){
			int a=ns%k;
			int b=cnt[there]%k;
			if((a+b)%k==0){
				tdp[2]+=((ll)dp[now][1]*dp[there][1])%mod;
				tdp[2]%=mod;
			}
			else if(a+b<k){
				tdp[1]+=((ll)dp[now][1]*dp[there][1])%mod;
				tdp[1]%=mod;
			}
		}
		// 2, 0
		tdp[2]+=((ll)dp[now][2]*dp[there][0])%mod;
		tdp[2]%=mod;
		for(int j=0;j<3;j++)
			dp[now][j]=tdp[j];
		ns+=cnt[there];
	}
	dp[now][0]+=dp[now][2];
	dp[now][0]%=mod;
}
int main(){
	//freopen("input2.txt", "r", stdin);
	//freopen("output2.txt", "w", stdout);
	int testcase;
	scanf("%d", &testcase);
	while(testcase--){
		memset(dp, 0, sizeof(dp));
		for(int i=0;i<maxn;i++)
			adj[i].clear();
		scanf("%d%d", &n, &k);
		for(int i=1;i<=n;i++)
			scanf("%d", &col[i]);
		for(int i=1;i<n;i++){
			int a, b;
			scanf("%d%d", &a, &b);
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		dfs(1, 0);
		printf("%d\n", dp[1][2]);
	}
	return 0;
}

