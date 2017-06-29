// =====================================================================================
// 
//       Filename:  12645.cpp
//        Created:  2017년 06월 29일 20시 28분 40초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> adj[1005];
int vnum;
int snum;
int dis[1005];
int scc[1005];
stack<int> st;
int deg[1005];
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
int main(){
	while(scanf("%d%d", &n, &m)!=EOF){
		for(int i=0;i<1005;i++){
			adj[i].clear();
		}
		for(int i=0;i<m;i++){
			int a, b;
			scanf("%d%d", &a, &b);
			if(b==0)
				continue;
			adj[a].push_back(b);
		}
		snum=vnum=0;
		memset(dis, -1, sizeof(dis));
		memset(scc, -1, sizeof(scc));
		for(int i=0;i<=n;i++)
			if(dis[i]==-1)
				dfs(i);
		memset(deg, 0, sizeof(deg));
		set<pair<int, int> > s;
		for(int i=0;i<=n;i++){
			int now=scc[i];
			for(int j=0;j<adj[i].size();j++){
				int there=scc[adj[i][j]];
				if(now!=there&&s.find({now, there})==s.end()){
					s.insert({now, there});
					deg[there]++;
				}
			}
		}
		int cnt=0;
		for(int i=0;i<snum;i++){
			if(deg[i]==0){
				cnt++;
			}
		}
		printf("%d\n", cnt-1);
	}

	return 0;
}

