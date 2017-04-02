// =====================================================================================
// 
//       Filename:  3736.cpp
//        Created:  2017년 04월 02일 23시 47분 53초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
int b[10005];
int level[10005];
bool trip[10005];
vector<int> adj[10005];
bool dfs(int v){
	for(int i=0;i<adj[v].size();i++){
		int there=adj[v][i];
		if(b[there]==-1||(level[b[there]]==level[v]+1&&dfs(b[there]))){
			trip[v]=true;
			b[there]=v;
			return true;
		}
	}
	return false;
}
int main(){
	while(scanf("%d", &n)!=EOF){
		for(int i=0;i<n;i++)
			adj[i].clear();
		for(int i=0;i<n;i++){
			int a, b;
			scanf("%d: (%d)", &a, &b);
			for(int j=0;j<b;j++){
				int in;
				scanf("%d", &in);
				adj[a].push_back(in-n);
			}
		}
		memset(trip, 0, sizeof(trip));
		memset(b, -1, sizeof(b));
		int total_flow=0;
		while(true){
			memset(level, -1, sizeof(level));
			queue<int> q;
			for(int i=0;i<n;i++){
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
					if(b[there]!=-1&&level[b[there]]==-1){
						level[b[there]]=level[now]+1;
						q.push(b[there]);
					}
				}
			}
			int flow=0;
			for(int i=0;i<n;i++){
				if(!trip[i]&&dfs(i)){
					flow++;
				}
			}
			if(flow==0)
				break;
			total_flow+=flow;
		}
		printf("%d\n", total_flow);
	}
	return 0;
}

