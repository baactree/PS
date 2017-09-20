// =====================================================================================
// 
//       Filename:  B.cpp
//        Created:  2017년 09월 20일 00시 08분 25초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
vector<int> adj[100005];
int cnta, cntb;
ll ans;
void dfs(int now, int par, int dep){
	if(dep&1)
		cntb++;
	else
		cnta++;
	for(int i=0;i<adj[now].size();i++){
		int there=adj[now][i];
		if(there==par)
			continue;
		dfs(there, now, dep+1);
	}
}
void dfs2(int now, int par, int dep){
	if(dep&1)
		ans+=cnta-adj[now].size();
	else
		ans+=cntb-adj[now].size();
	for(int i=0;i<adj[now].size();i++){
		int there=adj[now][i];
		if(there==par)
			continue;
		dfs2(there, now, dep+1);
	}
}
int main(){
	scanf("%d", &n);
	for(int i=0;i+1<n;i++){
		int a, b;
		scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1, 0, 0);
	dfs2(1, 0, 0);
	printf("%lld\n", ans/2);
	return 0;
}

