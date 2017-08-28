// =====================================================================================
// 
//       Filename:  2584.cpp
//        Created:  2017년 08월 16일 19시 51분 33초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, k;
int dp[1005][1005][2];
int ldp[1005][2];
int cnt[1005];
vector<pair<int, int> > adj[1005];
const int inf=0x3f3f3f3f;
void dfs(int now, int par){
	cnt[now]=1;
	for(int i=0;i<adj[now].size();i++){
		int there=adj[now][i].first;
		if(there==par)
			continue;
		dfs(there, now);
		cnt[now]+=cnt[there];
	}
	dp[now][1][1]=0;
	dp[now][0][0]=0;
	int kk=1;
	for(int q=0;q<adj[now].size();q++){
		int there=adj[now][q].first;
		if(there==par)
			continue;
		int cost=adj[now][q].second;
		memset(ldp, 0x3f, sizeof(ldp));
		for(int i=0;i<=kk;i++)
			for(int j=0;j<=cnt[there];j++){
				ldp[i+j][1]=min(ldp[i+j][1], dp[now][i][1]+dp[there][j][1]+cost);
				ldp[i+j][1]=min(ldp[i+j][1], dp[now][i][1]+dp[there][j][0]);
				ldp[i+j][0]=min(ldp[i+j][0], dp[now][i][0]+dp[there][j][1]);
				ldp[i+j][0]=min(ldp[i+j][0], dp[now][i][0]+dp[there][j][0]+cost);
			}
		kk+=cnt[there];
		for(int i=0;i<=kk;i++){
			dp[now][i][0]=ldp[i][0];
			dp[now][i][1]=ldp[i][1];
		}
	}
}
vector<int> ans;
int idx[1005][1005][2];
int tdp[1005][2];
void get_ans(int now, int par, int pick, int kk){
	if(pick){
		ans.push_back(now);
	}
	memset(tdp, 0x3f, sizeof(tdp));
	tdp[1][1]=0;
	tdp[0][0]=0;
	int pp=1;
	memset(idx, 0x3f, sizeof(idx));
	for(int q=0;q<adj[now].size();q++){
		int there=adj[now][q].first;
		if(there==par)
			continue;
		int cost=adj[now][q].second;
		memset(ldp, 0x3f, sizeof(ldp));
		for(int i=0;i<=pp;i++)
			for(int j=0;j<=cnt[there];j++){
				if(ldp[i+j][1]>tdp[i][1]+dp[there][j][1]+cost){
					ldp[i+j][1]=tdp[i][1]+dp[there][j][1]+cost;
					idx[q][i+j][1]=j;
				}
				if(ldp[i+j][1]>tdp[i][1]+dp[there][j][0]){
					ldp[i+j][1]=tdp[i][1]+dp[there][j][0];
					idx[q][i+j][1]=-j;
				}
				if(ldp[i+j][0]>tdp[i][0]+dp[there][j][1]){
					ldp[i+j][0]=tdp[i][0]+dp[there][j][1];
					idx[q][i+j][0]=j;
				}
				if(ldp[i+j][0]>tdp[i][0]+dp[there][j][0]+cost){
					ldp[i+j][0]=tdp[i][0]+dp[there][j][0]+cost;
					idx[q][i+j][0]=-j;
				}
			}
		pp+=cnt[there];
		for(int i=0;i<=pp;i++){
			tdp[i][0]=ldp[i][0];
			tdp[i][1]=ldp[i][1];
		}
	}
	int q=adj[now].size()-1;
	int w=kk;
	int e=pick;
	vector<pair<pair<int, int>, pair<int, int> > > vec;
	while(q>=0){
		int next=idx[q][w][e];
		int there=adj[now][q--].first;
		if(there==par)
			continue;
		int npick=next>0;
		next=abs(next);
		vec.push_back(make_pair(make_pair(there, now), make_pair(npick, next)));
		w-=next;
	}
	for(int i=0;i<vec.size();i++)
		get_ans(vec[i].first.first, vec[i].first.second, vec[i].second.first, vec[i].second.second);
}
int main(){
	memset(dp, 0x3f, sizeof(dp));
	scanf("%d%d", &n, &k);
	for(int i=1;i<n;i++){
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		adj[a].push_back({b, c});
		adj[b].push_back({a, c});
	}
	dfs(1, 0);
	printf("%d\n", min(dp[1][k][0], dp[1][k][1]));
	get_ans(1, 0, dp[1][k][0]>dp[1][k][1], k);
	sort(ans.begin(), ans.end());
	for(int i=0;i<ans.size();i++)
		printf("%d ", ans[i]);
	printf("\n");
	return 0;
}

