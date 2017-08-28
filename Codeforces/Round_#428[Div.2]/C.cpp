// =====================================================================================
// 
//       Filename:  C.cpp
//        Created:  2017년 08월 14일 15시 42분 42초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
double dist[100005];
vector<int> adj[100005];
void dfs(int now, int par){
	int cnt=0;
	for(int i=0;i<adj[now].size();i++){
		int there=adj[now][i];
		if(there==par)
			continue;
		cnt++;
	}
	for(int i=0;i<adj[now].size();i++){
		int there=adj[now][i];
		if(there==par)
			continue;
		dfs(there, now);
		dist[now]+=(dist[there]+1)/cnt;
	}
}
int main(){
	scanf("%d", &n);
	for(int i=1;i<n;i++){
		int a, b;
		scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1, 0);
	printf("%.10lf\n", dist[1]);
	return 0;
}

