// =====================================================================================
// 
//       Filename:  3295.cpp
//        Created:  2017년 05월 12일 15시 07분 09초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> adj[1000];
int level[1000];
bool trip[1000];
int matched[1000];
void bfs(){
	memset(level, -1, sizeof(level));
	queue<int> q;
	for(int i=0;i<n;i++)
		if(!trip[i]){
			q.push(i);
			level[i]=0;
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
}
bool dfs(int now){
	for(int i=0;i<adj[now].size();i++){
		int there=adj[now][i];
		if(matched[there]==-1||(level[matched[there]]==level[now]+1&&dfs(matched[there]))){
			matched[there]=now;
			trip[now]=true;
			return true;
		}
	}
	return false;
}
int flow(){
	int ret=0;
	memset(trip, 0, sizeof(trip));
	memset(matched, -1, sizeof(matched));
	while(true){
		bfs();
		int f=0;
		for(int i=0;i<n;i++)
			if(!trip[i]&&dfs(i))
				f++;		
		if(f==0)
			break;
		ret+=f;
	}
	return ret;
}
int main(){
	int testcase;
	scanf("%d", &testcase);
	while(testcase--){
		scanf("%d%d", &n, &m);
		for(int i=0;i<n;i++)
			adj[i].clear();
		for(int i=0;i<m;i++){
			int	u, v;
			scanf("%d%d", &u, &v);
			adj[u].push_back(v);
		}
		printf("%d\n", flow());
	}
	return 0;
}

