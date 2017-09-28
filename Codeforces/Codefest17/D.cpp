// =====================================================================================
// 
//       Filename:  D.cpp
//        Created:  2017년 09월 25일 01시 19분 10초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
vector<pair<int, int> > adj[100005];
int parp[100005][17], pars[100005][17];
int depth[100005];
void dfs(int now, int dep){
	depth[now]=dep;
	for(int i=0;i<adj[now].size();i++){
		int there=adj[now][i].first;
		int type=adj[now][i].second;
		if(type){
			parp[there][0]=now;
			for(int j=1;j<17;j++)
				parp[there][j]=parp[parp[there][j-1]][j-1];
		}
		else{
			pars[there][0]=now;
			for(int j=1;j<17;j++)
				pars[there][j]=pars[pars[there][j-1]][j-1];
		}
		dfs(there, dep+1);
	}
}
bool query(int type, int u, int v){
	if(u==v)
		return false;
	if(type==1){
		for(int i=16;i>=0;i--)
			if(pars[v][i]>=u){
				v=pars[v][i];
			}
		return u==v;
	}
	else{
		int t=v;
		for(int i=16;i>=0;i--)
			if(parp[t][i]>=u)
				t=parp[t][i];
		if(t==u)
			return true;
		if(depth[v]<depth[u]){
			for(int i=16;i>=0;i--)
				if(depth[u]-depth[v]>=1<<i)
					u=pars[u][i];
		}
		else{
			for(int i=16;i>=0;i--)
				if(depth[v]-depth[u]>=1<<i)
					v=parp[v][i];
		}
		for(int i=16;i>=0;i--){
			if(parp[v][i]&&pars[u][i]&&parp[v][i]!=pars[u][i]){
				v=parp[v][i];
				u=pars[u][i];
			}
		}
		return parp[v][0]==pars[u][0]&&parp[v][0];
	}
}
int main(){
	scanf("%d", &n);
	for(int i=1;i<=n;i++){
		int a, b;
		scanf("%d%d", &a, &b);
		if(b!=-1)
			adj[a].push_back({i, b});
	}
	for(int i=1;i<=n;i++)
		if(!depth[i])
			dfs(i, 1);
	int q;
	scanf("%d", &q);
	while(q--){
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		printf("%s\n", query(a, b, c)?"YES":"NO");
	}
	return 0;
}

