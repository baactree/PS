// =====================================================================================
// 
//       Filename:  C.cpp
//        Created:  2017년 03월 31일 16시 10분 58초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> adj[200001];
int color[200001];
void dfs(int now, int par, int gpc, int pc, int nc){
	color[now]=nc;
	int nextcolor=1;
	for(int i=0;i<adj[now].size();i++){
		int there=adj[now][i];
		if(there==par)
			continue;
		while(nextcolor==pc||nextcolor==nc)
			nextcolor++;
		dfs(there, now, pc, nc, nextcolor);
		nextcolor++;
	}
}
int main(){
	scanf("%d", &n);
	for(int i=0;i<n-1;i++){
		int a, b;
		scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1, 0, -1, -1, 1);
	int k=0;
	for(int i=1;i<=n;i++){
		k=max(k, color[i]);
	}
	printf("%d\n", k);
	for(int i=1;i<=n;i++)
		printf("%d ", color[i]);
	printf("\n");
	return 0;
}
