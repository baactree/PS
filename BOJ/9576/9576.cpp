// =====================================================================================
// 
//       Filename:  9576.cpp
//        Created:  2017년 04월 07일 17시 06분 00초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
bool trip[1001];
vector<int> adj[1001];
int matched[1001];
int level[1001];
int n, m;
bool dfs(int v){
	for(int i=0;i<adj[v].size();i++){
		int there=adj[v][i];
		if(matched[there]==-1||(level[matched[there]]==level[v]+1&&dfs(matched[there]))){
			matched[there]=v;
			trip[v]=true;
			return true;
		}
	}
	return false;
}
int main(){
	int tc;
	scanf("%d", &tc);
	while(tc--){
		scanf("%d%d", &n, &m);
		for(int i=1;i<=m;i++)
			adj[i].clear();
		for(int i=1;i<=m;i++){
			int a, b;
			scanf("%d%d", &a, &b);
			for(int j=a;j<=b;j++)
				adj[i].push_back(j);
		}
		memset(matched, -1, sizeof(matched));
		memset(trip, 0, sizeof(trip));
		int total_flow=0;
		while(true){
			memset(level, -1, sizeof(level));
			queue<int> q;
			for(int i=1;i<=m;i++){
				if(!trip[i]){
					q.push(i);
					level[i]=0;
				}
			}
			while(!q.empty()){
				int now=q.front();
				q.pop();
				for(int i=0;i<adj[now].size();i++){
					int there=adj[now][i];
					if(matched[there]!=-1&&level[matched[there]]==-1){
						level[matched[there]]=level[now]+1;
						q.push(matched[there]);
					}
				}
			}
			int flow=0;
			for(int i=1;i<=m;i++)
				if(!trip[i]&&dfs(i))
					flow++;
			if(flow==0)
				break;
			total_flow+=flow;
		}
		printf("%d\n", total_flow);
	}
	return 0;
}

