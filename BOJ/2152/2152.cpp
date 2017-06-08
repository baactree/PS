// =====================================================================================
// 
//       Filename:  2152.cpp
//        Created:  2017년 06월 08일 15시 49분 03초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> adj[10005];
int s, t;
int dis[10005];
int scc[10005];
int sccs[10005];
vector<int> sadj[10005];
int vertex_num, scc_num;
stack<int> st;
int cache[10005];
int dfs(int now){
	int ret=dis[now]=vertex_num++;
	st.push(now);
	for(int i=0;i<adj[now].size();i++){
		int there=adj[now][i];
		if(dis[there]==-1)
			ret=min(ret, dfs(there));
		else if(scc[there]==-1)
			ret=min(ret, dis[there]);
	}
	if(ret==dis[now]){
		int cnt=0;
		while(true){
			int temp=st.top();
			st.pop();
			scc[temp]=scc_num;
			cnt++;
			if(temp==now)
				break;
		}
		sccs[scc_num]=cnt;
		scc_num++;
	}
	return ret;
}
const int inf=0x3f3f3f3f;
int solve(int now){
	if(now==t)
		return sccs[now];
	int &ret=cache[now];
	if(ret!=-inf)
		return ret;
	for(int i=0;i<sadj[now].size();i++)
		ret=max(ret, solve(sadj[now][i])+sccs[now]);
	return ret;
}
int main(){
	scanf("%d%d", &n, &m);
	scanf("%d%d", &s, &t);
	for(int i=0;i<m;i++){
		int a, b;
		scanf("%d%d", &a, &b);
		adj[a].push_back(b);
	}
	memset(dis, -1, sizeof(dis));
	memset(scc, -1, sizeof(scc));
	for(int i=1;i<=n;i++){
		if(dis[i]==-1)
			dfs(i);
	}
	for(int i=1;i<=n;i++){
		int now=scc[i];
		for(int j=0;j<adj[i].size();j++){
			int there=adj[i][j];
			there=scc[there];
			if(now!=there)
				sadj[now].push_back(there);
		}
	}
	for(int i=0;i<scc_num;i++){
		sort(sadj[i].begin(), sadj[i].end());
		sadj[i].erase(unique(sadj[i].begin(), sadj[i].end()), sadj[i].end());
	}
	s=scc[s];
	t=scc[t];
	fill(cache, cache+10005, -inf);
	int ans=solve(s);
	printf("%d\n", ans<=-n*3?0:ans);
	return 0;
}

