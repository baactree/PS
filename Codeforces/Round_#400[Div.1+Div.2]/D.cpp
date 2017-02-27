// =====================================================================================
// 
//       Filename:  D.cpp
//        Created:  2017년 02월 26일 00시 47분 20초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National Uiversity
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m;
int door[100001];
vector<pair<int, int> > adj[100000];
vector<int> p[100001];
int color[100000];
bool trip[100000];
bool flag;
void dfs(int v, int col){
	trip[v]=true;
	color[v]=col;
	for(int i=0;i<adj[v].size();i++){
		int there=adj[v][i].first;
		int open=adj[v][i].second;
		int ncolor=col;
		if(open==0)
			ncolor=1-col;
		if(!trip[there])
			dfs(there, ncolor);
		else if(ncolor!=color[there])
			flag=true;
	}
}
int main(){
	scanf("%d%d", &n, &m);
	for(int i=0;i<n;i++)
		scanf("%d", &door[i+1]);
	for(int i=0;i<m;i++){
		int in;
		scanf("%d", &in);
		for(int j=0;j<in;j++){
			int x;
			scanf("%d", &x);
			p[x].push_back(i);
		}
	}
	for(int i=1;i<=n;i++){
		int a=p[i][0];
		int b=p[i][1];
		int c=door[i];
		adj[a].push_back({b, c});
		adj[b].push_back({a, c});
	}
	memset(color, -1, sizeof(color));
	for(int i=0;i<m;i++)
		if(!trip[i])
			dfs(i, 0);
	printf("%s\n", flag?"No":"Yes");
	return 0;
}

