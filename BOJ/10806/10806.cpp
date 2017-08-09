// =====================================================================================
// 
//       Filename:  10806.cpp
//        Created:  2017년 08월 09일 20시 26분 41초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<pair<int, int> > adj[100005];
int dis[100005];
int bridge[200005];
int vn;
int dfs(int now, int par){
	int ret=dis[now]=vn++;
	for(int i=0;i<adj[now].size();i++){
		int idx=adj[now][i].second;
		if(idx==par)
			continue;
		int there=adj[now][i].first;
		int temp=-1;
		if(dis[there]==-1){
			temp=dfs(there, idx);
			if(temp>dis[now])
				bridge[idx]=true;
			ret=min(ret, temp);
		}
		else
			ret=min(ret, dis[there]);
	}
	return ret;
}
int comp[100005];
int cn;
int cv[100005];
int out[100005];
void dfs2(int now, int cnt){
	comp[now]=cnt;
	for(int i=0;i<adj[now].size();i++){
		int idx=adj[now][i].second;
		if(bridge[idx])
			continue;
		int there=adj[now][i].first;
		if(comp[there]==-1)
			dfs2(there, cnt);
	}
}
pair<int,int> edge[200005];
int main(){
	scanf("%d%d", &n, &m);
	for(int i=0;i<m;i++){
		int a, b;
		scanf("%d%d", &a, &b);
		adj[a].push_back({b, i});
		adj[b].push_back({a, i});
		edge[i]={a, b};
	}
	memset(dis, -1, sizeof(dis));
	dfs(1, -1);
	memset(comp, -1, sizeof(comp));
	for(int i=1;i<=n;i++)
		if(comp[i]==-1){
			cv[cn]=i;
			dfs2(i, cn);
			cn++;
		}
	for(int i=0;i<m;i++)
		if(bridge[i]){
			out[comp[edge[i].first]]++;
			out[comp[edge[i].second]]++;
		}
	vector<int> ans;
	for(int i=0;i<cn;i++)
		if(out[i]==1)
			ans.push_back(i);
	if(ans.size()%2==1)
		ans.push_back(ans[0]);
	cout<<ans.size()/2<<endl;
	for(int i=0;i<ans.size();i+=2)
		printf("%d %d\n", cv[ans[i]], cv[ans[i+1]]);
	return 0;
}

