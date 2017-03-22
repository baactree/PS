// =====================================================================================
// 
//       Filename:  2637.cpp
//        Created:  2017년 03월 22일 14시 28분 43초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<pair<int, int> > adj[101];
int ans[101];
void dfs(int v, int cnt){
	if(adj[v].size()==0){
		ans[v]+=cnt;
		return;
	}
	for(int i=0;i<adj[v].size();i++){
		int there=adj[v][i].first;
		int there_cnt=adj[v][i].second;
		dfs(there, cnt*there_cnt);
	}
}
int main(){
	scanf("%d%d", &n, &m);
	for(int i=0;i<m;i++){
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		adj[a].push_back({b, c});
	}
	dfs(n, 1);
	for(int i=1;i<=n;i++){
		if(ans[i]!=0)
			printf("%d %d\n", i, ans[i]);
	}
	return 0;
}

