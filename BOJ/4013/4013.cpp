// =====================================================================================
// 
//       Filename:  4013.cpp
//        Created:  2017년 06월 27일 11시 27분 59초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m;
int arr[500005];
int sarr[500005];
int s, p;
int vnum, snum;
int scc[500005];
int dis[500005];
vector<int> adj[500005];
vector<int> sadj[500005];
int cache[500005];
stack<int> st;
const int inf=0x3f3f3f3f;
int dfs(int now){
	int ret=dis[now]=vnum++;
	st.push(now);
	for(int i=0;i<adj[now].size();i++){
		int there=adj[now][i];
		if(dis[there]==-1)
			ret=min(ret, dfs(there));
		else if(scc[there]==-1)
			ret=min(ret, dis[there]);
	}
	if(ret==dis[now]){
		while(true){
			int temp=st.top();
			st.pop();
			scc[temp]=snum;
			if(temp==now)
				break;
		}
		snum++;
	}
	return ret;
}
int solve(int now){
	if(now==scc[n])
		return 0;
	int &ret=cache[now];
	if(ret!=-inf)
		return ret;
	int k=sarr[now];
	for(int i=0;i<sadj[now].size();i++){
		int there=sadj[now][i];
		ret=max(ret, solve(there)+k);
	}
	return ret;
}
int main(){
	scanf("%d%d", &n, &m);
	for(int i=0;i<m;i++){
		int a, b;
		scanf("%d%d", &a, &b);
		adj[a].push_back(b);
	}
	for(int i=1;i<=n;i++)
		scanf("%d", &arr[i]);
	scanf("%d%d", &s, &p);
	for(int i=0;i<p;i++){
		int in;
		scanf("%d", &in);
		adj[in].push_back(n+1);
	}
	n++;
	memset(dis, -1, sizeof(dis));
	memset(scc, -1, sizeof(scc));
	for(int i=1;i<=n;i++)
		if(dis[i]==-1)
			dfs(i);
	for(int i=1;i<=n;i++){
		int now=scc[i];
		for(int j=0;j<adj[i].size();j++){
			int there=scc[adj[i][j]];
			if(now!=there)
				sadj[now].push_back(there);
		}
	}
	for(int i=1;i<=n;i++){
		int now=scc[i];
		sarr[now]+=arr[i];
	}
	for(int i=0;i<snum;i++){
		sort(sadj[i].begin(), sadj[i].end());
		sadj[i].erase(unique(sadj[i].begin(), sadj[i].end()), sadj[i].end());
	}
	for(int i=0;i<500005;i++)
		cache[i]=-inf;
	printf("%d\n", solve(scc[s]));
	return 0;
}

