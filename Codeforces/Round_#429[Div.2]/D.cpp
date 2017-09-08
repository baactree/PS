// =====================================================================================
// 
//       Filename:  D.cpp
//        Created:  2017년 09월 08일 03시 59분 28초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > adj[300005];
int d[300005];
bool trip[300005];
int n, m;
vector<int> ans;
void dfs(int now, int par){
	trip[now]=true;
	vector<int> vec;
	for(int i=0;i<adj[now].size();i++){
		int there=adj[now][i].first;
		if(there==par||trip[there])
			continue;
		vec.push_back(i);
		dfs(there, now);
	}
	for(int i=0;i<vec.size();i++){
		int there=adj[now][vec[i]].first;
		int idx=adj[now][vec[i]].second;
		if(there==par)
			continue;
		if(d[there]){
			ans.push_back(idx);
			d[now]=1-d[now];
		}
	}
}
int main(){
	scanf("%d%d", &n, &m);
	int cnt=0;
	int sum=0;
	for(int i=1;i<=n;i++){
		scanf("%d", &d[i]);
		if(d[i]==-1)
			cnt++;
		else
			sum+=d[i];
	}
	for(int i=1;i<=m;i++){
		int a, b;
		scanf("%d%d", &a, &b);
		adj[a].push_back({b, i});
		adj[b].push_back({a, i});
	}
	if((sum&1)&&!cnt)
		return !printf("-1\n");
	if(sum&1)
		cnt=1;
	else
		cnt=0;
	for(int i=1;i<=n;i++){
		if(d[i]==-1&&cnt){
			d[i]=1;
			cnt--;
		}
		if(d[i]==-1)
			d[i]=0;
	}
	dfs(1, 0);
	printf("%d\n", ans.size());
	for(int i=0;i<ans.size();i++)
		printf("%d ", ans[i]);
	printf("\n");
	return 0;
}

